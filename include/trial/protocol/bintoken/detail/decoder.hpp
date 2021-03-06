#ifndef TRIAL_PROTOCOL_BINTOKEN_DETAIL_DECODER_HPP
#define TRIAL_PROTOCOL_BINTOKEN_DETAIL_DECODER_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2015 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <cstdint>
#include <boost/config.hpp>
#include <trial/protocol/core/detail/string_view.hpp>
#include <trial/protocol/core/char_traits.hpp>
#include <trial/protocol/bintoken/token.hpp>
#include <trial/protocol/bintoken/error.hpp>

namespace trial
{
namespace protocol
{
namespace bintoken
{
namespace detail
{

class decoder
{
public:
    using value_type = std::uint8_t;
    using size_type = std::size_t;
    using view_type = core::detail::basic_string_view<value_type, core::char_traits<value_type>>;

    decoder(view_type);
    template <typename T> decoder(const T& input);

    void next() BOOST_NOEXCEPT;

    void code(token::code::value) BOOST_NOEXCEPT;
    token::code::value code() const BOOST_NOEXCEPT;
    token::symbol::value symbol() const BOOST_NOEXCEPT;
    token::category::value category() const BOOST_NOEXCEPT;
    std::error_code error() const BOOST_NOEXCEPT;

    const view_type& literal() const BOOST_NOEXCEPT;
    const view_type& tail() const BOOST_NOEXCEPT;
    template <typename Tag> typename Tag::type value() const;

    size_type array(token::int8::type *output, size_type output_length);
    size_type array(token::int16::type *output, size_type output_length);
    size_type array(token::int32::type *output, size_type output_length);
    size_type array(token::int64::type *output, size_type output_length);
    size_type array(token::float32::type *output, size_type output_length);
    size_type array(token::float64::type *output, size_type output_length);

private:
    token::code::value next(value_type, std::int64_t) BOOST_NOEXCEPT;
    token::code::value next_length(value_type, size_type) BOOST_NOEXCEPT;

    template <typename Tag>
    token::code::value advance() BOOST_NOEXCEPT;

    template <typename Tag>
    token::code::value advance(value_type) BOOST_NOEXCEPT;

private:
    template <typename ReturnType> struct overloader;

    view_type input;
    struct
    {
        mutable token::code::value code;
        view_type view;
    } current;
};

} // namespace detail
} // namespace bintoken
} // namespace protocol
} // namespace trial

#include <trial/protocol/bintoken/detail/decoder.ipp>

#endif // TRIAL_PROTOCOL_BINTOKEN_DETAIL_DECODER_HPP
