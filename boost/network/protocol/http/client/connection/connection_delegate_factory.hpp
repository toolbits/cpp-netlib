#ifndef BOOST_NETWORK_PROTOCOL_HTTP_CLIENT_CONNECTION_DELEGATE_FACTORY_HPP_20110819
#define BOOST_NETWORK_PROTOCOL_HTTP_CLIENT_CONNECTION_DELEGATE_FACTORY_HPP_20110819

// Copyright 2011 Dean Michael Berris (dberris@google.com).
// Copyright 2011 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/throw_exception.hpp>
#include <boost/network/protocol/http/client/connection/connection_delegate.hpp>

namespace boost { namespace network { namespace http {

struct connection_delegate_factory {
  typedef shared_ptr<connection_delegate> connection_delegate_ptr;

  connection_delegate_factory();

  // This is the factory method that actually returns the delegate instance.
  // TODO Support passing in proxy settings when crafting connections.
  virtual connection_delegate_ptr create_connection_delegate(
      asio::io_service & service,
      bool https,
      optional<std::string> certificate_filename,
      optional<std::string> verify_path);

  virtual ~connection_delegate_factory();

 private:
  connection_delegate_factory(connection_delegate_factory const &);  // = delete
  connection_delegate_factory& operator=(connection_delegate_factory);  // = delete
};

} /* http */
} /* network */
} /* boost */

#ifdef BOOST_NETWORK_NO_LIB
#include <boost/network/protocol/http/client/connection/connection_delegate_factory.ipp>
#endif

#endif /* BOOST_NETWORK_PROTOCOL_HTTP_CLIENT_CONNECTION_DELEGATE_FACTORY_HPP_20110819 */
