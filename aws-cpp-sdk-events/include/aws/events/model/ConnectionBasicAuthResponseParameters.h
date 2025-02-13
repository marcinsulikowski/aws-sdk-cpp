﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/events/CloudWatchEvents_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace CloudWatchEvents
{
namespace Model
{

  /**
   * <p>Contains the authorization parameters for the connection if Basic is
   * specified as the authorization type.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/events-2015-10-07/ConnectionBasicAuthResponseParameters">AWS
   * API Reference</a></p>
   */
  class AWS_CLOUDWATCHEVENTS_API ConnectionBasicAuthResponseParameters
  {
  public:
    ConnectionBasicAuthResponseParameters();
    ConnectionBasicAuthResponseParameters(Aws::Utils::Json::JsonView jsonValue);
    ConnectionBasicAuthResponseParameters& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The user name to use for Basic authorization.</p>
     */
    inline const Aws::String& GetUsername() const{ return m_username; }

    /**
     * <p>The user name to use for Basic authorization.</p>
     */
    inline bool UsernameHasBeenSet() const { return m_usernameHasBeenSet; }

    /**
     * <p>The user name to use for Basic authorization.</p>
     */
    inline void SetUsername(const Aws::String& value) { m_usernameHasBeenSet = true; m_username = value; }

    /**
     * <p>The user name to use for Basic authorization.</p>
     */
    inline void SetUsername(Aws::String&& value) { m_usernameHasBeenSet = true; m_username = std::move(value); }

    /**
     * <p>The user name to use for Basic authorization.</p>
     */
    inline void SetUsername(const char* value) { m_usernameHasBeenSet = true; m_username.assign(value); }

    /**
     * <p>The user name to use for Basic authorization.</p>
     */
    inline ConnectionBasicAuthResponseParameters& WithUsername(const Aws::String& value) { SetUsername(value); return *this;}

    /**
     * <p>The user name to use for Basic authorization.</p>
     */
    inline ConnectionBasicAuthResponseParameters& WithUsername(Aws::String&& value) { SetUsername(std::move(value)); return *this;}

    /**
     * <p>The user name to use for Basic authorization.</p>
     */
    inline ConnectionBasicAuthResponseParameters& WithUsername(const char* value) { SetUsername(value); return *this;}

  private:

    Aws::String m_username;
    bool m_usernameHasBeenSet = false;
  };

} // namespace Model
} // namespace CloudWatchEvents
} // namespace Aws
