﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/apigateway/APIGateway_EXPORTS.h>
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
namespace APIGateway
{
namespace Model
{

  /**
   * <p>The requested service is not available. For details see the accompanying
   * error message. Retry after the specified time period.</p><p><h3>See Also:</h3>  
   * <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/apigateway-2015-07-09/ServiceUnavailableException">AWS
   * API Reference</a></p>
   */
  class AWS_APIGATEWAY_API ServiceUnavailableException
  {
  public:
    ServiceUnavailableException();
    ServiceUnavailableException(Aws::Utils::Json::JsonView jsonValue);
    ServiceUnavailableException& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    
    inline const Aws::String& GetRetryAfterSeconds() const{ return m_retryAfterSeconds; }

    
    inline bool RetryAfterSecondsHasBeenSet() const { return m_retryAfterSecondsHasBeenSet; }

    
    inline void SetRetryAfterSeconds(const Aws::String& value) { m_retryAfterSecondsHasBeenSet = true; m_retryAfterSeconds = value; }

    
    inline void SetRetryAfterSeconds(Aws::String&& value) { m_retryAfterSecondsHasBeenSet = true; m_retryAfterSeconds = std::move(value); }

    
    inline void SetRetryAfterSeconds(const char* value) { m_retryAfterSecondsHasBeenSet = true; m_retryAfterSeconds.assign(value); }

    
    inline ServiceUnavailableException& WithRetryAfterSeconds(const Aws::String& value) { SetRetryAfterSeconds(value); return *this;}

    
    inline ServiceUnavailableException& WithRetryAfterSeconds(Aws::String&& value) { SetRetryAfterSeconds(std::move(value)); return *this;}

    
    inline ServiceUnavailableException& WithRetryAfterSeconds(const char* value) { SetRetryAfterSeconds(value); return *this;}


    
    inline const Aws::String& GetMessage() const{ return m_message; }

    
    inline bool MessageHasBeenSet() const { return m_messageHasBeenSet; }

    
    inline void SetMessage(const Aws::String& value) { m_messageHasBeenSet = true; m_message = value; }

    
    inline void SetMessage(Aws::String&& value) { m_messageHasBeenSet = true; m_message = std::move(value); }

    
    inline void SetMessage(const char* value) { m_messageHasBeenSet = true; m_message.assign(value); }

    
    inline ServiceUnavailableException& WithMessage(const Aws::String& value) { SetMessage(value); return *this;}

    
    inline ServiceUnavailableException& WithMessage(Aws::String&& value) { SetMessage(std::move(value)); return *this;}

    
    inline ServiceUnavailableException& WithMessage(const char* value) { SetMessage(value); return *this;}

  private:

    Aws::String m_retryAfterSeconds;
    bool m_retryAfterSecondsHasBeenSet = false;

    Aws::String m_message;
    bool m_messageHasBeenSet = false;
  };

} // namespace Model
} // namespace APIGateway
} // namespace Aws
