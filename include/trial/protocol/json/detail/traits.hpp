#ifndef TRIAL_PROTOCOL_JSON_DETAIL_TRAITS_HPP
#define TRIAL_PROTOCOL_JSON_DETAIL_TRAITS_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2015 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <cstddef> // std::size_t
#include <string>
#include <boost/config.hpp>
#include <trial/protocol/core/char_traits.hpp>

namespace trial
{
namespace protocol
{
namespace json
{
namespace detail
{

template <typename CharT>
class traits
{
};

enum class traits_category
{
    narrow,
    extra_1,
    extra_2,
    extra_3,
    extra_4,
    extra_5,
    quote,
    escape,
    illegal
};

//-----------------------------------------------------------------------------
// char specialization
//-----------------------------------------------------------------------------

template <>
class traits<char>
{
public:
    using value_type = char;
    using string_type = std::basic_string<value_type, core::char_traits<value_type>>;

    static bool is_space(value_type value) BOOST_NOEXCEPT;
    static bool is_digit(value_type value) BOOST_NOEXCEPT;
    static bool is_hexdigit(value_type value) BOOST_NOEXCEPT;
    static bool is_keyword(value_type value) BOOST_NOEXCEPT;
    static traits_category to_category(value_type value) BOOST_NOEXCEPT;
    static int to_int(value_type value) BOOST_NOEXCEPT;

    static const string_type& false_text() BOOST_NOEXCEPT;
    static const string_type& true_text() BOOST_NOEXCEPT;
    static const string_type& null_text() BOOST_NOEXCEPT;

    BOOST_STATIC_CONSTANT(value_type, alpha_backspace = '\b');
    BOOST_STATIC_CONSTANT(value_type, alpha_formfeed = '\f');
    BOOST_STATIC_CONSTANT(value_type, alpha_newline = '\n');
    BOOST_STATIC_CONSTANT(value_type, alpha_tab = '\t');
    BOOST_STATIC_CONSTANT(value_type, alpha_return = '\r');
    BOOST_STATIC_CONSTANT(value_type, alpha_quote = '"');
    BOOST_STATIC_CONSTANT(value_type, alpha_plus = '+');
    BOOST_STATIC_CONSTANT(value_type, alpha_comma = ',');
    BOOST_STATIC_CONSTANT(value_type, alpha_minus = '-');
    BOOST_STATIC_CONSTANT(value_type, alpha_dot = '.');
    BOOST_STATIC_CONSTANT(value_type, alpha_solidus = '/');
    BOOST_STATIC_CONSTANT(value_type, alpha_0 = '0');
    BOOST_STATIC_CONSTANT(value_type, alpha_1 = '1');
    BOOST_STATIC_CONSTANT(value_type, alpha_2 = '2');
    BOOST_STATIC_CONSTANT(value_type, alpha_3 = '3');
    BOOST_STATIC_CONSTANT(value_type, alpha_4 = '4');
    BOOST_STATIC_CONSTANT(value_type, alpha_5 = '5');
    BOOST_STATIC_CONSTANT(value_type, alpha_6 = '6');
    BOOST_STATIC_CONSTANT(value_type, alpha_7 = '7');
    BOOST_STATIC_CONSTANT(value_type, alpha_8 = '8');
    BOOST_STATIC_CONSTANT(value_type, alpha_9 = '9');
    BOOST_STATIC_CONSTANT(value_type, alpha_colon = ':');
    BOOST_STATIC_CONSTANT(value_type, alpha_question_mark = '?');
    BOOST_STATIC_CONSTANT(value_type, alpha_A = 'A');
    BOOST_STATIC_CONSTANT(value_type, alpha_E = 'E');
    BOOST_STATIC_CONSTANT(value_type, alpha_a = 'a');
    BOOST_STATIC_CONSTANT(value_type, alpha_b = 'b');
    BOOST_STATIC_CONSTANT(value_type, alpha_e = 'e');
    BOOST_STATIC_CONSTANT(value_type, alpha_f = 'f');
    BOOST_STATIC_CONSTANT(value_type, alpha_n = 'n');
    BOOST_STATIC_CONSTANT(value_type, alpha_r = 'r');
    BOOST_STATIC_CONSTANT(value_type, alpha_t = 't');
    BOOST_STATIC_CONSTANT(value_type, alpha_u = 'u');
    BOOST_STATIC_CONSTANT(value_type, alpha_bracket_open = '[');
    BOOST_STATIC_CONSTANT(value_type, alpha_reverse_solidus = '\\');
    BOOST_STATIC_CONSTANT(value_type, alpha_bracket_close = ']');
    BOOST_STATIC_CONSTANT(value_type, alpha_brace_open = '{');
    BOOST_STATIC_CONSTANT(value_type, alpha_brace_close = '}');

private:
    static bool is_hex_upper(value_type value) BOOST_NOEXCEPT;
    static bool is_hex_lower(value_type value) BOOST_NOEXCEPT;
};

//-----------------------------------------------------------------------------
// unsigned char specialization
//-----------------------------------------------------------------------------

template <>
class traits<unsigned char>
{
public:
    using value_type = unsigned char;
    using string_type = std::basic_string<value_type, core::char_traits<value_type>>;

    static bool is_space(value_type value) BOOST_NOEXCEPT;
    static bool is_digit(value_type value) BOOST_NOEXCEPT;
    static bool is_hexdigit(value_type value) BOOST_NOEXCEPT;
    static bool is_keyword(value_type value) BOOST_NOEXCEPT;
    static traits_category to_category(value_type value) BOOST_NOEXCEPT;
    static int to_int(value_type value) BOOST_NOEXCEPT;

    static const string_type& false_text() BOOST_NOEXCEPT;
    static const string_type& true_text() BOOST_NOEXCEPT;
    static const string_type& null_text() BOOST_NOEXCEPT;

    BOOST_STATIC_CONSTANT(value_type, alpha_backspace = '\b');
    BOOST_STATIC_CONSTANT(value_type, alpha_formfeed = '\f');
    BOOST_STATIC_CONSTANT(value_type, alpha_newline = '\n');
    BOOST_STATIC_CONSTANT(value_type, alpha_tab = '\t');
    BOOST_STATIC_CONSTANT(value_type, alpha_return = '\r');
    BOOST_STATIC_CONSTANT(value_type, alpha_quote = '"');
    BOOST_STATIC_CONSTANT(value_type, alpha_plus = '+');
    BOOST_STATIC_CONSTANT(value_type, alpha_comma = ',');
    BOOST_STATIC_CONSTANT(value_type, alpha_minus = '-');
    BOOST_STATIC_CONSTANT(value_type, alpha_dot = '.');
    BOOST_STATIC_CONSTANT(value_type, alpha_solidus = '/');
    BOOST_STATIC_CONSTANT(value_type, alpha_0 = '0');
    BOOST_STATIC_CONSTANT(value_type, alpha_1 = '1');
    BOOST_STATIC_CONSTANT(value_type, alpha_2 = '2');
    BOOST_STATIC_CONSTANT(value_type, alpha_3 = '3');
    BOOST_STATIC_CONSTANT(value_type, alpha_4 = '4');
    BOOST_STATIC_CONSTANT(value_type, alpha_5 = '5');
    BOOST_STATIC_CONSTANT(value_type, alpha_6 = '6');
    BOOST_STATIC_CONSTANT(value_type, alpha_7 = '7');
    BOOST_STATIC_CONSTANT(value_type, alpha_8 = '8');
    BOOST_STATIC_CONSTANT(value_type, alpha_9 = '9');
    BOOST_STATIC_CONSTANT(value_type, alpha_colon = ':');
    BOOST_STATIC_CONSTANT(value_type, alpha_question_mark = '?');
    BOOST_STATIC_CONSTANT(value_type, alpha_A = 'A');
    BOOST_STATIC_CONSTANT(value_type, alpha_E = 'E');
    BOOST_STATIC_CONSTANT(value_type, alpha_a = 'a');
    BOOST_STATIC_CONSTANT(value_type, alpha_b = 'b');
    BOOST_STATIC_CONSTANT(value_type, alpha_e = 'e');
    BOOST_STATIC_CONSTANT(value_type, alpha_f = 'f');
    BOOST_STATIC_CONSTANT(value_type, alpha_n = 'n');
    BOOST_STATIC_CONSTANT(value_type, alpha_r = 'r');
    BOOST_STATIC_CONSTANT(value_type, alpha_t = 't');
    BOOST_STATIC_CONSTANT(value_type, alpha_u = 'u');
    BOOST_STATIC_CONSTANT(value_type, alpha_bracket_open = '[');
    BOOST_STATIC_CONSTANT(value_type, alpha_reverse_solidus = '\\');
    BOOST_STATIC_CONSTANT(value_type, alpha_bracket_close = ']');
    BOOST_STATIC_CONSTANT(value_type, alpha_brace_open = '{');
    BOOST_STATIC_CONSTANT(value_type, alpha_brace_close = '}');

private:
    static bool is_hex_upper(value_type value) BOOST_NOEXCEPT;
    static bool is_hex_lower(value_type value) BOOST_NOEXCEPT;
};

} // namespace detail
} // namespace json
} // namespace protocol
} // namespace trial

#include <trial/protocol/json/detail/traits.ipp>

#endif // TRIAL_PROTOCOL_JSON_DETAIL_TRAITS_HPP
