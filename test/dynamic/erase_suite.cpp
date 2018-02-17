///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2018 Vinícius dos Santos Oliveira <vini.ipsmaker@gmail.com>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <trial/protocol/core/detail/lightweight_test.hpp>
#include <trial/dynamic/variable.hpp>
#include <trial/dynamic/algorithm/erase.hpp>

using namespace trial::dynamic;

//-----------------------------------------------------------------------------
// key::erase
//-----------------------------------------------------------------------------

void key_erase_null()
{
    variable data, data2;
    // Cannot iterate over null, so nothing changes
    auto it = data.key_begin();
    TRIAL_PROTOCOL_TEST(key::erase(data, 0) == it);
    TRIAL_PROTOCOL_TEST(data == data2);
}

void key_erase_string_matching_key()
{
    variable data("test");
    TRIAL_PROTOCOL_TEST(data == "test");
    auto it = key::erase(data, "test");
    TRIAL_PROTOCOL_TEST(it == data.key_end());
    TRIAL_PROTOCOL_TEST(data == "test");
}

void key_erase_first_out_of_three_on_list()
{
    variable data{"test", 2, 3};
    auto it = key::erase(data, "test");
    TRIAL_PROTOCOL_TEST(it == data.key_end());
    TRIAL_PROTOCOL_TEST(*data.begin() == "test");
}

void key_erase_first_out_of_three()
{
    variable data;
    data["a"] = 1;
    data["b"] = 2;
    data["c"] = 3;
    auto it = key::erase(data, std::string("a"));
    TRIAL_PROTOCOL_TEST(it == data.key_begin());
    TRIAL_PROTOCOL_TEST(*it == "b");
    TRIAL_PROTOCOL_TEST(data.size() == 2);
}

void key_erase_last()
{
    variable data;
    data["a"] = 1;
    data["b"] = 2;
    data["c"] = 3;
    auto it = key::erase(data, std::string("c"));
    TRIAL_PROTOCOL_TEST(it == data.key_end());
    TRIAL_PROTOCOL_TEST(data.size() == 2);
    TRIAL_PROTOCOL_TEST(data["a"] == 1);
    TRIAL_PROTOCOL_TEST(data["b"] == 2);
}

void key_erase_on_one_sized_map()
{
    variable data;
    data["a"] = 1;
    auto it = key::erase(data, std::string("a"));
    TRIAL_PROTOCOL_TEST(it == data.key_end());
    TRIAL_PROTOCOL_TEST(data.size() == 0);
}

int main()
{
    key_erase_null();
    key_erase_string_matching_key();
    key_erase_first_out_of_three_on_list();
    key_erase_first_out_of_three();
    key_erase_last();
    key_erase_on_one_sized_map();
}
