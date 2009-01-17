
//         Copyright E�in O'Callaghan 2009 - 2009.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "halTorrentInternal.hpp"

#include <boost/statechart/event.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/statechart/custom_reaction.hpp>

namespace hal 
{

namespace sc = boost::statechart;

struct ev_remove_from_session : boost::statechart::event<ev_remove_from_session>
{
public:
    ev_remove_from_session(bool write_data) :
		write_data_(write_data)
    {}
   
    const bool& write_data() const { return write_data_; }

private:
    bool write_data_;
};

struct ev_add_to_session : boost::statechart::event<ev_add_to_session>
{
public:
    ev_add_to_session(bool pause) :
		pause_(pause)
    {}
   
    const bool& pause() const { return pause_; }

private:
    bool pause_;
};

struct ev_pause : sc::event< ev_pause > {};
struct ev_paused_alert : sc::event<ev_paused_alert> {};

struct ev_stop : sc::event< ev_stop > {};

struct ev_write_resume_data : sc::event< ev_stop > {};
struct ev_resume_data_written : sc::event<ev_resume_data_written> {};

} // namespace hal