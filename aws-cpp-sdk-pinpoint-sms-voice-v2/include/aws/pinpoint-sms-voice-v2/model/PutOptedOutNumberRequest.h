﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/pinpoint-sms-voice-v2/PinpointSMSVoiceV2_EXPORTS.h>
#include <aws/pinpoint-sms-voice-v2/PinpointSMSVoiceV2Request.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace PinpointSMSVoiceV2
{
namespace Model
{

  /**
   */
  class AWS_PINPOINTSMSVOICEV2_API PutOptedOutNumberRequest : public PinpointSMSVoiceV2Request
  {
  public:
    PutOptedOutNumberRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "PutOptedOutNumber"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The OptOutListName or OptOutListArn to add the phone number to.</p>
     */
    inline const Aws::String& GetOptOutListName() const{ return m_optOutListName; }

    /**
     * <p>The OptOutListName or OptOutListArn to add the phone number to.</p>
     */
    inline bool OptOutListNameHasBeenSet() const { return m_optOutListNameHasBeenSet; }

    /**
     * <p>The OptOutListName or OptOutListArn to add the phone number to.</p>
     */
    inline void SetOptOutListName(const Aws::String& value) { m_optOutListNameHasBeenSet = true; m_optOutListName = value; }

    /**
     * <p>The OptOutListName or OptOutListArn to add the phone number to.</p>
     */
    inline void SetOptOutListName(Aws::String&& value) { m_optOutListNameHasBeenSet = true; m_optOutListName = std::move(value); }

    /**
     * <p>The OptOutListName or OptOutListArn to add the phone number to.</p>
     */
    inline void SetOptOutListName(const char* value) { m_optOutListNameHasBeenSet = true; m_optOutListName.assign(value); }

    /**
     * <p>The OptOutListName or OptOutListArn to add the phone number to.</p>
     */
    inline PutOptedOutNumberRequest& WithOptOutListName(const Aws::String& value) { SetOptOutListName(value); return *this;}

    /**
     * <p>The OptOutListName or OptOutListArn to add the phone number to.</p>
     */
    inline PutOptedOutNumberRequest& WithOptOutListName(Aws::String&& value) { SetOptOutListName(std::move(value)); return *this;}

    /**
     * <p>The OptOutListName or OptOutListArn to add the phone number to.</p>
     */
    inline PutOptedOutNumberRequest& WithOptOutListName(const char* value) { SetOptOutListName(value); return *this;}


    /**
     * <p>The phone number to add to the OptOutList in E.164 format.</p>
     */
    inline const Aws::String& GetOptedOutNumber() const{ return m_optedOutNumber; }

    /**
     * <p>The phone number to add to the OptOutList in E.164 format.</p>
     */
    inline bool OptedOutNumberHasBeenSet() const { return m_optedOutNumberHasBeenSet; }

    /**
     * <p>The phone number to add to the OptOutList in E.164 format.</p>
     */
    inline void SetOptedOutNumber(const Aws::String& value) { m_optedOutNumberHasBeenSet = true; m_optedOutNumber = value; }

    /**
     * <p>The phone number to add to the OptOutList in E.164 format.</p>
     */
    inline void SetOptedOutNumber(Aws::String&& value) { m_optedOutNumberHasBeenSet = true; m_optedOutNumber = std::move(value); }

    /**
     * <p>The phone number to add to the OptOutList in E.164 format.</p>
     */
    inline void SetOptedOutNumber(const char* value) { m_optedOutNumberHasBeenSet = true; m_optedOutNumber.assign(value); }

    /**
     * <p>The phone number to add to the OptOutList in E.164 format.</p>
     */
    inline PutOptedOutNumberRequest& WithOptedOutNumber(const Aws::String& value) { SetOptedOutNumber(value); return *this;}

    /**
     * <p>The phone number to add to the OptOutList in E.164 format.</p>
     */
    inline PutOptedOutNumberRequest& WithOptedOutNumber(Aws::String&& value) { SetOptedOutNumber(std::move(value)); return *this;}

    /**
     * <p>The phone number to add to the OptOutList in E.164 format.</p>
     */
    inline PutOptedOutNumberRequest& WithOptedOutNumber(const char* value) { SetOptedOutNumber(value); return *this;}

  private:

    Aws::String m_optOutListName;
    bool m_optOutListNameHasBeenSet = false;

    Aws::String m_optedOutNumber;
    bool m_optedOutNumberHasBeenSet = false;
  };

} // namespace Model
} // namespace PinpointSMSVoiceV2
} // namespace Aws
