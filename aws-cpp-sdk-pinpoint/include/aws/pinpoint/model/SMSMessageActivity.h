﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/pinpoint/Pinpoint_EXPORTS.h>
#include <aws/pinpoint/model/JourneySMSMessage.h>
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
namespace Pinpoint
{
namespace Model
{

  /**
   * <p>Specifies the settings for an SMS activity in a journey. This type of
   * activity sends a text message to participants.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/pinpoint-2016-12-01/SMSMessageActivity">AWS
   * API Reference</a></p>
   */
  class AWS_PINPOINT_API SMSMessageActivity
  {
  public:
    SMSMessageActivity();
    SMSMessageActivity(Aws::Utils::Json::JsonView jsonValue);
    SMSMessageActivity& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>Specifies the sender ID and message type for an SMS message that's sent to
     * participants in a journey.</p>
     */
    inline const JourneySMSMessage& GetMessageConfig() const{ return m_messageConfig; }

    /**
     * <p>Specifies the sender ID and message type for an SMS message that's sent to
     * participants in a journey.</p>
     */
    inline bool MessageConfigHasBeenSet() const { return m_messageConfigHasBeenSet; }

    /**
     * <p>Specifies the sender ID and message type for an SMS message that's sent to
     * participants in a journey.</p>
     */
    inline void SetMessageConfig(const JourneySMSMessage& value) { m_messageConfigHasBeenSet = true; m_messageConfig = value; }

    /**
     * <p>Specifies the sender ID and message type for an SMS message that's sent to
     * participants in a journey.</p>
     */
    inline void SetMessageConfig(JourneySMSMessage&& value) { m_messageConfigHasBeenSet = true; m_messageConfig = std::move(value); }

    /**
     * <p>Specifies the sender ID and message type for an SMS message that's sent to
     * participants in a journey.</p>
     */
    inline SMSMessageActivity& WithMessageConfig(const JourneySMSMessage& value) { SetMessageConfig(value); return *this;}

    /**
     * <p>Specifies the sender ID and message type for an SMS message that's sent to
     * participants in a journey.</p>
     */
    inline SMSMessageActivity& WithMessageConfig(JourneySMSMessage&& value) { SetMessageConfig(std::move(value)); return *this;}


    /**
     * <p>The unique identifier for the next activity to perform, after the message is
     * sent.</p>
     */
    inline const Aws::String& GetNextActivity() const{ return m_nextActivity; }

    /**
     * <p>The unique identifier for the next activity to perform, after the message is
     * sent.</p>
     */
    inline bool NextActivityHasBeenSet() const { return m_nextActivityHasBeenSet; }

    /**
     * <p>The unique identifier for the next activity to perform, after the message is
     * sent.</p>
     */
    inline void SetNextActivity(const Aws::String& value) { m_nextActivityHasBeenSet = true; m_nextActivity = value; }

    /**
     * <p>The unique identifier for the next activity to perform, after the message is
     * sent.</p>
     */
    inline void SetNextActivity(Aws::String&& value) { m_nextActivityHasBeenSet = true; m_nextActivity = std::move(value); }

    /**
     * <p>The unique identifier for the next activity to perform, after the message is
     * sent.</p>
     */
    inline void SetNextActivity(const char* value) { m_nextActivityHasBeenSet = true; m_nextActivity.assign(value); }

    /**
     * <p>The unique identifier for the next activity to perform, after the message is
     * sent.</p>
     */
    inline SMSMessageActivity& WithNextActivity(const Aws::String& value) { SetNextActivity(value); return *this;}

    /**
     * <p>The unique identifier for the next activity to perform, after the message is
     * sent.</p>
     */
    inline SMSMessageActivity& WithNextActivity(Aws::String&& value) { SetNextActivity(std::move(value)); return *this;}

    /**
     * <p>The unique identifier for the next activity to perform, after the message is
     * sent.</p>
     */
    inline SMSMessageActivity& WithNextActivity(const char* value) { SetNextActivity(value); return *this;}


    /**
     * <p>The name of the SMS message template to use for the message. If specified,
     * this value must match the name of an existing message template.</p>
     */
    inline const Aws::String& GetTemplateName() const{ return m_templateName; }

    /**
     * <p>The name of the SMS message template to use for the message. If specified,
     * this value must match the name of an existing message template.</p>
     */
    inline bool TemplateNameHasBeenSet() const { return m_templateNameHasBeenSet; }

    /**
     * <p>The name of the SMS message template to use for the message. If specified,
     * this value must match the name of an existing message template.</p>
     */
    inline void SetTemplateName(const Aws::String& value) { m_templateNameHasBeenSet = true; m_templateName = value; }

    /**
     * <p>The name of the SMS message template to use for the message. If specified,
     * this value must match the name of an existing message template.</p>
     */
    inline void SetTemplateName(Aws::String&& value) { m_templateNameHasBeenSet = true; m_templateName = std::move(value); }

    /**
     * <p>The name of the SMS message template to use for the message. If specified,
     * this value must match the name of an existing message template.</p>
     */
    inline void SetTemplateName(const char* value) { m_templateNameHasBeenSet = true; m_templateName.assign(value); }

    /**
     * <p>The name of the SMS message template to use for the message. If specified,
     * this value must match the name of an existing message template.</p>
     */
    inline SMSMessageActivity& WithTemplateName(const Aws::String& value) { SetTemplateName(value); return *this;}

    /**
     * <p>The name of the SMS message template to use for the message. If specified,
     * this value must match the name of an existing message template.</p>
     */
    inline SMSMessageActivity& WithTemplateName(Aws::String&& value) { SetTemplateName(std::move(value)); return *this;}

    /**
     * <p>The name of the SMS message template to use for the message. If specified,
     * this value must match the name of an existing message template.</p>
     */
    inline SMSMessageActivity& WithTemplateName(const char* value) { SetTemplateName(value); return *this;}


    /**
     * <p>The unique identifier for the version of the SMS template to use for the
     * message. If specified, this value must match the identifier for an existing
     * template version. To retrieve a list of versions and version identifiers for a
     * template, use the <link 
     * linkend="templates-template-name-template-type-versions">Template
     * Versions</link> resource.</p> <p>If you don't specify a value for this property,
     * Amazon Pinpoint uses the <i>active version</i> of the template. The <i>active
     * version</i> is typically the version of a template that's been most recently
     * reviewed and approved for use, depending on your workflow. It isn't necessarily
     * the latest version of a template.</p>
     */
    inline const Aws::String& GetTemplateVersion() const{ return m_templateVersion; }

    /**
     * <p>The unique identifier for the version of the SMS template to use for the
     * message. If specified, this value must match the identifier for an existing
     * template version. To retrieve a list of versions and version identifiers for a
     * template, use the <link 
     * linkend="templates-template-name-template-type-versions">Template
     * Versions</link> resource.</p> <p>If you don't specify a value for this property,
     * Amazon Pinpoint uses the <i>active version</i> of the template. The <i>active
     * version</i> is typically the version of a template that's been most recently
     * reviewed and approved for use, depending on your workflow. It isn't necessarily
     * the latest version of a template.</p>
     */
    inline bool TemplateVersionHasBeenSet() const { return m_templateVersionHasBeenSet; }

    /**
     * <p>The unique identifier for the version of the SMS template to use for the
     * message. If specified, this value must match the identifier for an existing
     * template version. To retrieve a list of versions and version identifiers for a
     * template, use the <link 
     * linkend="templates-template-name-template-type-versions">Template
     * Versions</link> resource.</p> <p>If you don't specify a value for this property,
     * Amazon Pinpoint uses the <i>active version</i> of the template. The <i>active
     * version</i> is typically the version of a template that's been most recently
     * reviewed and approved for use, depending on your workflow. It isn't necessarily
     * the latest version of a template.</p>
     */
    inline void SetTemplateVersion(const Aws::String& value) { m_templateVersionHasBeenSet = true; m_templateVersion = value; }

    /**
     * <p>The unique identifier for the version of the SMS template to use for the
     * message. If specified, this value must match the identifier for an existing
     * template version. To retrieve a list of versions and version identifiers for a
     * template, use the <link 
     * linkend="templates-template-name-template-type-versions">Template
     * Versions</link> resource.</p> <p>If you don't specify a value for this property,
     * Amazon Pinpoint uses the <i>active version</i> of the template. The <i>active
     * version</i> is typically the version of a template that's been most recently
     * reviewed and approved for use, depending on your workflow. It isn't necessarily
     * the latest version of a template.</p>
     */
    inline void SetTemplateVersion(Aws::String&& value) { m_templateVersionHasBeenSet = true; m_templateVersion = std::move(value); }

    /**
     * <p>The unique identifier for the version of the SMS template to use for the
     * message. If specified, this value must match the identifier for an existing
     * template version. To retrieve a list of versions and version identifiers for a
     * template, use the <link 
     * linkend="templates-template-name-template-type-versions">Template
     * Versions</link> resource.</p> <p>If you don't specify a value for this property,
     * Amazon Pinpoint uses the <i>active version</i> of the template. The <i>active
     * version</i> is typically the version of a template that's been most recently
     * reviewed and approved for use, depending on your workflow. It isn't necessarily
     * the latest version of a template.</p>
     */
    inline void SetTemplateVersion(const char* value) { m_templateVersionHasBeenSet = true; m_templateVersion.assign(value); }

    /**
     * <p>The unique identifier for the version of the SMS template to use for the
     * message. If specified, this value must match the identifier for an existing
     * template version. To retrieve a list of versions and version identifiers for a
     * template, use the <link 
     * linkend="templates-template-name-template-type-versions">Template
     * Versions</link> resource.</p> <p>If you don't specify a value for this property,
     * Amazon Pinpoint uses the <i>active version</i> of the template. The <i>active
     * version</i> is typically the version of a template that's been most recently
     * reviewed and approved for use, depending on your workflow. It isn't necessarily
     * the latest version of a template.</p>
     */
    inline SMSMessageActivity& WithTemplateVersion(const Aws::String& value) { SetTemplateVersion(value); return *this;}

    /**
     * <p>The unique identifier for the version of the SMS template to use for the
     * message. If specified, this value must match the identifier for an existing
     * template version. To retrieve a list of versions and version identifiers for a
     * template, use the <link 
     * linkend="templates-template-name-template-type-versions">Template
     * Versions</link> resource.</p> <p>If you don't specify a value for this property,
     * Amazon Pinpoint uses the <i>active version</i> of the template. The <i>active
     * version</i> is typically the version of a template that's been most recently
     * reviewed and approved for use, depending on your workflow. It isn't necessarily
     * the latest version of a template.</p>
     */
    inline SMSMessageActivity& WithTemplateVersion(Aws::String&& value) { SetTemplateVersion(std::move(value)); return *this;}

    /**
     * <p>The unique identifier for the version of the SMS template to use for the
     * message. If specified, this value must match the identifier for an existing
     * template version. To retrieve a list of versions and version identifiers for a
     * template, use the <link 
     * linkend="templates-template-name-template-type-versions">Template
     * Versions</link> resource.</p> <p>If you don't specify a value for this property,
     * Amazon Pinpoint uses the <i>active version</i> of the template. The <i>active
     * version</i> is typically the version of a template that's been most recently
     * reviewed and approved for use, depending on your workflow. It isn't necessarily
     * the latest version of a template.</p>
     */
    inline SMSMessageActivity& WithTemplateVersion(const char* value) { SetTemplateVersion(value); return *this;}

  private:

    JourneySMSMessage m_messageConfig;
    bool m_messageConfigHasBeenSet = false;

    Aws::String m_nextActivity;
    bool m_nextActivityHasBeenSet = false;

    Aws::String m_templateName;
    bool m_templateNameHasBeenSet = false;

    Aws::String m_templateVersion;
    bool m_templateVersionHasBeenSet = false;
  };

} // namespace Model
} // namespace Pinpoint
} // namespace Aws
