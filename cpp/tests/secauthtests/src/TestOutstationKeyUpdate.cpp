/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#include <catch.hpp>

#include "fixtures/OutstationSecAuthFixture.h"

#include <dnp3mocks/APDUHexBuilders.h>
#include <testlib/HexConversions.h>

using namespace std;
using namespace opendnp3;
using namespace secauth;
using namespace openpal;
using namespace testlib;

#define SUITE(name) "OutstationKeyUpdateTestSuite - " name

TEST_CASE(SUITE("Rejects user status change when authority is not configured"))
{		
	OutstationSecAuthFixture fixture;
	fixture.AddUser(User::Default(), 0xFF, UpdateKeyMode::AES128);
	fixture.LowerLayerUp();

	AppSeqNum seq;
	uint16_t statusChangeSeq = 0;

	auto userStatusChangeRequest = hex::UserStatusChangeRequest(
		seq,
		KeyChangeMethod::AES_256_SHA256_HMAC,
		UserOperation::OP_ADD,
		statusChangeSeq,
		UserRoleToType(UserRole::OPERATOR),
		365,
		"Jim",
		"",
		"DEADBEEF"
		);

	auto response = hex::AuthErrorResponse(IINBit::DEVICE_RESTART, seq, statusChangeSeq, User::UNKNOWN_ID, 0, AuthErrorCode::UPDATE_KEY_METHOD_NOT_PERMITTED, DNPTime(0), "");

	REQUIRE(fixture.SendAndReceive(userStatusChangeRequest) == response);
}


