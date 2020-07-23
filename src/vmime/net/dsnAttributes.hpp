//
// VMime library (http://www.vmime.org)
// Copyright (C) 2020 Jan Osusky <jan@osusky.name>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// Linking this library statically or dynamically with other modules is making
// a combined work based on this library.  Thus, the terms and conditions of
// the GNU General Public License cover the whole combination.
//

#ifndef VMIME_NET_DSNATTRIBUTES_HPP_INCLUDED
#define VMIME_NET_DSNATTRIBUTES_HPP_INCLUDED


#include "vmime/config.hpp"


#if VMIME_HAVE_MESSAGING_FEATURES


#include <vector>

#include "vmime/types.hpp"


namespace vmime {
namespace net {


/** Holds a set of attributes for Delivery Status Notifications (DSN).
  */
class VMIME_EXPORT dsnAttributes : public object {

public:

	/** Constructs an empty dsnAttributes object.
	  */
	dsnAttributes() = default;

	/** Constructs a new dsnAttributes object by copying an existing object.
	  *
	  * @param dsn object to copy
	  */
	dsnAttributes(const dsnAttributes& dsn) = default;

	/** Constructs a new dsnAttributes object by moving an existing object.
	  *
	  * @param dsn object (Rvalue reference) to move from.
	  */
	dsnAttributes(dsnAttributes&& dsn) = default;

	~dsnAttributes() = default;

	/** Constructs a new dsnAttributes object by specifying the attributes.
	  *
	  * @param dsnNotify comma separated list of notification conditions as specified in RFC 1891
	  * @param dsnRet content of DSN - full message or headers only ("FULL" or "HDRS")
	  * @param dsnEnvelopId envelop ID to be able to pair the DSN with original message (plain text not in "<" ">")
	  */
	dsnAttributes(string dsnNotify, string dsnRet, string dsnEnvelopId);

	/** Returns comma separated list of notification conditions as specified in RFC 1891
	  *
	  * @return comma separated list of notification conditions as specified in RFC 1891
	  */
	string notificationConditions() const;

	/** Returns requested format of the notification (RET parameter of the ESMTP MAIL command).
	  *
	  * @return requested format of the notification.
	  */
	string returnFormat() const;

	/** Returns envelop ID used pair the DSN with the original message.
	  *
	  * @return envelop ID used pair the DSN with the original message.
	  */
	string envelopId() const;

private:

	string m_notifications;
	string m_returnFormat;
	string m_envelopId;
};


} // net
} // vmime


#endif // VMIME_HAVE_MESSAGING_FEATURES


#endif // VMIME_NET_DSNATTRIBUTES_HPP_INCLUDED
