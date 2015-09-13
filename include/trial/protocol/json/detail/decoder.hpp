#ifndef TRIAL_PROTOCOL_JSON_DETAIL_DECODER_HPP
#define TRIAL_PROTOCOL_JSON_DETAIL_DECODER_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2015 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <string>
#include <boost/cstdint.hpp>
#include <boost/config.hpp>
#include <boost/system/error_code.hpp>
#include <boost/utility/string_ref.hpp>
#include <trial/protocol/json/token.hpp>
#include <trial/protocol/json/error.hpp>

namespace trial
{
namespace protocol
{
namespace json
{
namespace detail
{

template <typename CharT>
class basic_decoder
{
public:
    typedef const CharT value_type;
    typedef boost::basic_string_ref<CharT> view_type;

    basic_decoder(const view_type& input);

    void next() BOOST_NOEXCEPT;

    void code(json::code::value) BOOST_NOEXCEPT;
    json::code::value code() const BOOST_NOEXCEPT;
    json::symbol::value symbol() const BOOST_NOEXCEPT;
    json::category::value category() const BOOST_NOEXCEPT;
    boost::system::error_code error() const BOOST_NOEXCEPT;
    const view_type& literal() const BOOST_NOEXCEPT;
    template <typename ReturnType> ReturnType value() const;

private:
    code::value next_token(code::value) BOOST_NOEXCEPT;
    code::value next_f_keyword() BOOST_NOEXCEPT;
    code::value next_n_keyword() BOOST_NOEXCEPT;
    code::value next_t_keyword() BOOST_NOEXCEPT;
    code::value next_number() BOOST_NOEXCEPT;
    code::value next_string() BOOST_NOEXCEPT;

    void skip_whitespaces() BOOST_NOEXCEPT;
    bool at_keyword_end() const BOOST_NOEXCEPT;

private:
    template <typename C, typename T, typename Enable> friend struct basic_decoder_functor;

    view_type input;
    struct
    {
        json::code::value code;
        view_type view;
    } current;
};

typedef basic_decoder<char> decoder;

} // namespace detail
} // namespace json
} // namespace protocol
} // namespace trial

#include <trial/protocol/json/detail/decoder.ipp>

#endif /* TRIAL_PROTOCOL_JSON_DETAIL_DECODER_HPP */
