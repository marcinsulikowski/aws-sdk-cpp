﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/pinpoint-sms-voice-v2/PinpointSMSVoiceV2_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/pinpoint-sms-voice-v2/model/ServiceQuotaExceededExceptionReason.h>
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
namespace PinpointSMSVoiceV2
{
namespace Model
{

  /**
   * <p>The request would cause a service quota to be exceeded.</p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/pinpoint-sms-voice-v2-2022-03-31/ServiceQuotaExceededException">AWS
   * API Reference</a></p>
   */
  class AWS_PINPOINTSMSVOICEV2_API ServiceQuotaExceededException
  {
  public:
    ServiceQuotaExceededException();
    ServiceQuotaExceededException(Aws::Utils::Json::JsonView jsonValue);
    ServiceQuotaExceededException& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    
    inline const Aws::String& GetMessage() const{ return m_message; }

    
    inline bool MessageHasBeenSet() const { return m_messageHasBeenSet; }

    
    inline void SetMessage(const Aws::String& value) { m_messageHasBeenSet = true; m_message = value; }

    
    inline void SetMessage(Aws::String&& value) { m_messageHasBeenSet = true; m_message = std::move(value); }

    
    inline void SetMessage(const char* value) { m_messageHasBeenSet = true; m_message.assign(value); }

    
    inline ServiceQuotaExceededException& WithMessage(const Aws::String& value) { SetMessage(value); return *this;}

    
    inline ServiceQuotaExceededException& WithMessage(Aws::String&& value) { SetMessage(std::move(value)); return *this;}

    
    inline ServiceQuotaExceededException& WithMessage(const char* value) { SetMessage(value); return *this;}


    /**
     * <p>The reason for the exception.</p>
     */
    inline const ServiceQuotaExceededExceptionReason& GetReason() const{ return m_reason; }

    /**
     * <p>The reason for the exception.</p>
     */
    inline bool ReasonHasBeenSet() const { return m_reasonHasBeenSet; }

    /**
     * <p>The reason for the exception.</p>
     */
    inline void SetReason(const ServiceQuotaExceededExceptionReason& value) { m_reasonHasBeenSet = true; m_reason = value; }

    /**
     * <p>The reason for the exception.</p>
     */
    inline void SetReason(ServiceQuotaExceededExceptionReason&& value) { m_reasonHasBeenSet = true; m_reason = std::move(value); }

    /**
     * <p>The reason for the exception.</p>
     */
    inline ServiceQuotaExceededException& WithReason(const ServiceQuotaExceededExceptionReason& value) { SetReason(value); return *this;}

    /**
     * <p>The reason for the exception.</p>
     */
    inline ServiceQuotaExceededException& WithReason(ServiceQuotaExceededExceptionReason&& value) { SetReason(std::move(value)); return *this;}

  private:

    Aws::String m_message;
    bool m_messageHasBeenSet = false;

    ServiceQuotaExceededExceptionReason m_reason;
    bool m_reasonHasBeenSet = false;
  };

} // namespace Model
} // namespace PinpointSMSVoiceV2
} // namespace Aws
