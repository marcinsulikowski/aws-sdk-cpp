﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/pinpoint/Pinpoint_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSMap.h>
#include <aws/pinpoint/model/TemplateType.h>
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
   * <p>Provides information about a message template that's associated with your
   * Amazon Pinpoint account.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/pinpoint-2016-12-01/TemplateResponse">AWS
   * API Reference</a></p>
   */
  class AWS_PINPOINT_API TemplateResponse
  {
  public:
    TemplateResponse();
    TemplateResponse(Aws::Utils::Json::JsonView jsonValue);
    TemplateResponse& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The Amazon Resource Name (ARN) of the message template. This value isn't
     * included in a TemplateResponse object. To retrieve the ARN of a template, use
     * the GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the ARN
     * for.</p>
     */
    inline const Aws::String& GetArn() const{ return m_arn; }

    /**
     * <p>The Amazon Resource Name (ARN) of the message template. This value isn't
     * included in a TemplateResponse object. To retrieve the ARN of a template, use
     * the GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the ARN
     * for.</p>
     */
    inline bool ArnHasBeenSet() const { return m_arnHasBeenSet; }

    /**
     * <p>The Amazon Resource Name (ARN) of the message template. This value isn't
     * included in a TemplateResponse object. To retrieve the ARN of a template, use
     * the GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the ARN
     * for.</p>
     */
    inline void SetArn(const Aws::String& value) { m_arnHasBeenSet = true; m_arn = value; }

    /**
     * <p>The Amazon Resource Name (ARN) of the message template. This value isn't
     * included in a TemplateResponse object. To retrieve the ARN of a template, use
     * the GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the ARN
     * for.</p>
     */
    inline void SetArn(Aws::String&& value) { m_arnHasBeenSet = true; m_arn = std::move(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the message template. This value isn't
     * included in a TemplateResponse object. To retrieve the ARN of a template, use
     * the GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the ARN
     * for.</p>
     */
    inline void SetArn(const char* value) { m_arnHasBeenSet = true; m_arn.assign(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the message template. This value isn't
     * included in a TemplateResponse object. To retrieve the ARN of a template, use
     * the GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the ARN
     * for.</p>
     */
    inline TemplateResponse& WithArn(const Aws::String& value) { SetArn(value); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the message template. This value isn't
     * included in a TemplateResponse object. To retrieve the ARN of a template, use
     * the GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the ARN
     * for.</p>
     */
    inline TemplateResponse& WithArn(Aws::String&& value) { SetArn(std::move(value)); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the message template. This value isn't
     * included in a TemplateResponse object. To retrieve the ARN of a template, use
     * the GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the ARN
     * for.</p>
     */
    inline TemplateResponse& WithArn(const char* value) { SetArn(value); return *this;}


    /**
     * <p>The date, in ISO 8601 format, when the message template was created.</p>
     */
    inline const Aws::String& GetCreationDate() const{ return m_creationDate; }

    /**
     * <p>The date, in ISO 8601 format, when the message template was created.</p>
     */
    inline bool CreationDateHasBeenSet() const { return m_creationDateHasBeenSet; }

    /**
     * <p>The date, in ISO 8601 format, when the message template was created.</p>
     */
    inline void SetCreationDate(const Aws::String& value) { m_creationDateHasBeenSet = true; m_creationDate = value; }

    /**
     * <p>The date, in ISO 8601 format, when the message template was created.</p>
     */
    inline void SetCreationDate(Aws::String&& value) { m_creationDateHasBeenSet = true; m_creationDate = std::move(value); }

    /**
     * <p>The date, in ISO 8601 format, when the message template was created.</p>
     */
    inline void SetCreationDate(const char* value) { m_creationDateHasBeenSet = true; m_creationDate.assign(value); }

    /**
     * <p>The date, in ISO 8601 format, when the message template was created.</p>
     */
    inline TemplateResponse& WithCreationDate(const Aws::String& value) { SetCreationDate(value); return *this;}

    /**
     * <p>The date, in ISO 8601 format, when the message template was created.</p>
     */
    inline TemplateResponse& WithCreationDate(Aws::String&& value) { SetCreationDate(std::move(value)); return *this;}

    /**
     * <p>The date, in ISO 8601 format, when the message template was created.</p>
     */
    inline TemplateResponse& WithCreationDate(const char* value) { SetCreationDate(value); return *this;}


    /**
     * <p>The JSON object that specifies the default values that are used for message
     * variables in the message template. This object isn't included in a
     * TemplateResponse object. To retrieve this object for a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * object for.</p>
     */
    inline const Aws::String& GetDefaultSubstitutions() const{ return m_defaultSubstitutions; }

    /**
     * <p>The JSON object that specifies the default values that are used for message
     * variables in the message template. This object isn't included in a
     * TemplateResponse object. To retrieve this object for a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * object for.</p>
     */
    inline bool DefaultSubstitutionsHasBeenSet() const { return m_defaultSubstitutionsHasBeenSet; }

    /**
     * <p>The JSON object that specifies the default values that are used for message
     * variables in the message template. This object isn't included in a
     * TemplateResponse object. To retrieve this object for a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * object for.</p>
     */
    inline void SetDefaultSubstitutions(const Aws::String& value) { m_defaultSubstitutionsHasBeenSet = true; m_defaultSubstitutions = value; }

    /**
     * <p>The JSON object that specifies the default values that are used for message
     * variables in the message template. This object isn't included in a
     * TemplateResponse object. To retrieve this object for a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * object for.</p>
     */
    inline void SetDefaultSubstitutions(Aws::String&& value) { m_defaultSubstitutionsHasBeenSet = true; m_defaultSubstitutions = std::move(value); }

    /**
     * <p>The JSON object that specifies the default values that are used for message
     * variables in the message template. This object isn't included in a
     * TemplateResponse object. To retrieve this object for a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * object for.</p>
     */
    inline void SetDefaultSubstitutions(const char* value) { m_defaultSubstitutionsHasBeenSet = true; m_defaultSubstitutions.assign(value); }

    /**
     * <p>The JSON object that specifies the default values that are used for message
     * variables in the message template. This object isn't included in a
     * TemplateResponse object. To retrieve this object for a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * object for.</p>
     */
    inline TemplateResponse& WithDefaultSubstitutions(const Aws::String& value) { SetDefaultSubstitutions(value); return *this;}

    /**
     * <p>The JSON object that specifies the default values that are used for message
     * variables in the message template. This object isn't included in a
     * TemplateResponse object. To retrieve this object for a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * object for.</p>
     */
    inline TemplateResponse& WithDefaultSubstitutions(Aws::String&& value) { SetDefaultSubstitutions(std::move(value)); return *this;}

    /**
     * <p>The JSON object that specifies the default values that are used for message
     * variables in the message template. This object isn't included in a
     * TemplateResponse object. To retrieve this object for a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * object for.</p>
     */
    inline TemplateResponse& WithDefaultSubstitutions(const char* value) { SetDefaultSubstitutions(value); return *this;}


    /**
     * <p>The date, in ISO 8601 format, when the message template was last
     * modified.</p>
     */
    inline const Aws::String& GetLastModifiedDate() const{ return m_lastModifiedDate; }

    /**
     * <p>The date, in ISO 8601 format, when the message template was last
     * modified.</p>
     */
    inline bool LastModifiedDateHasBeenSet() const { return m_lastModifiedDateHasBeenSet; }

    /**
     * <p>The date, in ISO 8601 format, when the message template was last
     * modified.</p>
     */
    inline void SetLastModifiedDate(const Aws::String& value) { m_lastModifiedDateHasBeenSet = true; m_lastModifiedDate = value; }

    /**
     * <p>The date, in ISO 8601 format, when the message template was last
     * modified.</p>
     */
    inline void SetLastModifiedDate(Aws::String&& value) { m_lastModifiedDateHasBeenSet = true; m_lastModifiedDate = std::move(value); }

    /**
     * <p>The date, in ISO 8601 format, when the message template was last
     * modified.</p>
     */
    inline void SetLastModifiedDate(const char* value) { m_lastModifiedDateHasBeenSet = true; m_lastModifiedDate.assign(value); }

    /**
     * <p>The date, in ISO 8601 format, when the message template was last
     * modified.</p>
     */
    inline TemplateResponse& WithLastModifiedDate(const Aws::String& value) { SetLastModifiedDate(value); return *this;}

    /**
     * <p>The date, in ISO 8601 format, when the message template was last
     * modified.</p>
     */
    inline TemplateResponse& WithLastModifiedDate(Aws::String&& value) { SetLastModifiedDate(std::move(value)); return *this;}

    /**
     * <p>The date, in ISO 8601 format, when the message template was last
     * modified.</p>
     */
    inline TemplateResponse& WithLastModifiedDate(const char* value) { SetLastModifiedDate(value); return *this;}


    /**
     * <p>A map of key-value pairs that identifies the tags that are associated with
     * the message template. This object isn't included in a TemplateResponse object.
     * To retrieve this object for a template, use the GetEmailTemplate,
     * GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate operation, depending on the
     * type of template that you want to retrieve the object for.</p>
     */
    inline const Aws::Map<Aws::String, Aws::String>& GetTags() const{ return m_tags; }

    /**
     * <p>A map of key-value pairs that identifies the tags that are associated with
     * the message template. This object isn't included in a TemplateResponse object.
     * To retrieve this object for a template, use the GetEmailTemplate,
     * GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate operation, depending on the
     * type of template that you want to retrieve the object for.</p>
     */
    inline bool TagsHasBeenSet() const { return m_tagsHasBeenSet; }

    /**
     * <p>A map of key-value pairs that identifies the tags that are associated with
     * the message template. This object isn't included in a TemplateResponse object.
     * To retrieve this object for a template, use the GetEmailTemplate,
     * GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate operation, depending on the
     * type of template that you want to retrieve the object for.</p>
     */
    inline void SetTags(const Aws::Map<Aws::String, Aws::String>& value) { m_tagsHasBeenSet = true; m_tags = value; }

    /**
     * <p>A map of key-value pairs that identifies the tags that are associated with
     * the message template. This object isn't included in a TemplateResponse object.
     * To retrieve this object for a template, use the GetEmailTemplate,
     * GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate operation, depending on the
     * type of template that you want to retrieve the object for.</p>
     */
    inline void SetTags(Aws::Map<Aws::String, Aws::String>&& value) { m_tagsHasBeenSet = true; m_tags = std::move(value); }

    /**
     * <p>A map of key-value pairs that identifies the tags that are associated with
     * the message template. This object isn't included in a TemplateResponse object.
     * To retrieve this object for a template, use the GetEmailTemplate,
     * GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate operation, depending on the
     * type of template that you want to retrieve the object for.</p>
     */
    inline TemplateResponse& WithTags(const Aws::Map<Aws::String, Aws::String>& value) { SetTags(value); return *this;}

    /**
     * <p>A map of key-value pairs that identifies the tags that are associated with
     * the message template. This object isn't included in a TemplateResponse object.
     * To retrieve this object for a template, use the GetEmailTemplate,
     * GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate operation, depending on the
     * type of template that you want to retrieve the object for.</p>
     */
    inline TemplateResponse& WithTags(Aws::Map<Aws::String, Aws::String>&& value) { SetTags(std::move(value)); return *this;}

    /**
     * <p>A map of key-value pairs that identifies the tags that are associated with
     * the message template. This object isn't included in a TemplateResponse object.
     * To retrieve this object for a template, use the GetEmailTemplate,
     * GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate operation, depending on the
     * type of template that you want to retrieve the object for.</p>
     */
    inline TemplateResponse& AddTags(const Aws::String& key, const Aws::String& value) { m_tagsHasBeenSet = true; m_tags.emplace(key, value); return *this; }

    /**
     * <p>A map of key-value pairs that identifies the tags that are associated with
     * the message template. This object isn't included in a TemplateResponse object.
     * To retrieve this object for a template, use the GetEmailTemplate,
     * GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate operation, depending on the
     * type of template that you want to retrieve the object for.</p>
     */
    inline TemplateResponse& AddTags(Aws::String&& key, const Aws::String& value) { m_tagsHasBeenSet = true; m_tags.emplace(std::move(key), value); return *this; }

    /**
     * <p>A map of key-value pairs that identifies the tags that are associated with
     * the message template. This object isn't included in a TemplateResponse object.
     * To retrieve this object for a template, use the GetEmailTemplate,
     * GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate operation, depending on the
     * type of template that you want to retrieve the object for.</p>
     */
    inline TemplateResponse& AddTags(const Aws::String& key, Aws::String&& value) { m_tagsHasBeenSet = true; m_tags.emplace(key, std::move(value)); return *this; }

    /**
     * <p>A map of key-value pairs that identifies the tags that are associated with
     * the message template. This object isn't included in a TemplateResponse object.
     * To retrieve this object for a template, use the GetEmailTemplate,
     * GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate operation, depending on the
     * type of template that you want to retrieve the object for.</p>
     */
    inline TemplateResponse& AddTags(Aws::String&& key, Aws::String&& value) { m_tagsHasBeenSet = true; m_tags.emplace(std::move(key), std::move(value)); return *this; }

    /**
     * <p>A map of key-value pairs that identifies the tags that are associated with
     * the message template. This object isn't included in a TemplateResponse object.
     * To retrieve this object for a template, use the GetEmailTemplate,
     * GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate operation, depending on the
     * type of template that you want to retrieve the object for.</p>
     */
    inline TemplateResponse& AddTags(const char* key, Aws::String&& value) { m_tagsHasBeenSet = true; m_tags.emplace(key, std::move(value)); return *this; }

    /**
     * <p>A map of key-value pairs that identifies the tags that are associated with
     * the message template. This object isn't included in a TemplateResponse object.
     * To retrieve this object for a template, use the GetEmailTemplate,
     * GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate operation, depending on the
     * type of template that you want to retrieve the object for.</p>
     */
    inline TemplateResponse& AddTags(Aws::String&& key, const char* value) { m_tagsHasBeenSet = true; m_tags.emplace(std::move(key), value); return *this; }

    /**
     * <p>A map of key-value pairs that identifies the tags that are associated with
     * the message template. This object isn't included in a TemplateResponse object.
     * To retrieve this object for a template, use the GetEmailTemplate,
     * GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate operation, depending on the
     * type of template that you want to retrieve the object for.</p>
     */
    inline TemplateResponse& AddTags(const char* key, const char* value) { m_tagsHasBeenSet = true; m_tags.emplace(key, value); return *this; }


    /**
     * <p>The custom description of the message template. This value isn't included in
     * a TemplateResponse object. To retrieve the description of a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * description for.</p>
     */
    inline const Aws::String& GetTemplateDescription() const{ return m_templateDescription; }

    /**
     * <p>The custom description of the message template. This value isn't included in
     * a TemplateResponse object. To retrieve the description of a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * description for.</p>
     */
    inline bool TemplateDescriptionHasBeenSet() const { return m_templateDescriptionHasBeenSet; }

    /**
     * <p>The custom description of the message template. This value isn't included in
     * a TemplateResponse object. To retrieve the description of a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * description for.</p>
     */
    inline void SetTemplateDescription(const Aws::String& value) { m_templateDescriptionHasBeenSet = true; m_templateDescription = value; }

    /**
     * <p>The custom description of the message template. This value isn't included in
     * a TemplateResponse object. To retrieve the description of a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * description for.</p>
     */
    inline void SetTemplateDescription(Aws::String&& value) { m_templateDescriptionHasBeenSet = true; m_templateDescription = std::move(value); }

    /**
     * <p>The custom description of the message template. This value isn't included in
     * a TemplateResponse object. To retrieve the description of a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * description for.</p>
     */
    inline void SetTemplateDescription(const char* value) { m_templateDescriptionHasBeenSet = true; m_templateDescription.assign(value); }

    /**
     * <p>The custom description of the message template. This value isn't included in
     * a TemplateResponse object. To retrieve the description of a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * description for.</p>
     */
    inline TemplateResponse& WithTemplateDescription(const Aws::String& value) { SetTemplateDescription(value); return *this;}

    /**
     * <p>The custom description of the message template. This value isn't included in
     * a TemplateResponse object. To retrieve the description of a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * description for.</p>
     */
    inline TemplateResponse& WithTemplateDescription(Aws::String&& value) { SetTemplateDescription(std::move(value)); return *this;}

    /**
     * <p>The custom description of the message template. This value isn't included in
     * a TemplateResponse object. To retrieve the description of a template, use the
     * GetEmailTemplate, GetPushTemplate, GetSmsTemplate, or GetVoiceTemplate
     * operation, depending on the type of template that you want to retrieve the
     * description for.</p>
     */
    inline TemplateResponse& WithTemplateDescription(const char* value) { SetTemplateDescription(value); return *this;}


    /**
     * <p>The name of the message template.</p>
     */
    inline const Aws::String& GetTemplateName() const{ return m_templateName; }

    /**
     * <p>The name of the message template.</p>
     */
    inline bool TemplateNameHasBeenSet() const { return m_templateNameHasBeenSet; }

    /**
     * <p>The name of the message template.</p>
     */
    inline void SetTemplateName(const Aws::String& value) { m_templateNameHasBeenSet = true; m_templateName = value; }

    /**
     * <p>The name of the message template.</p>
     */
    inline void SetTemplateName(Aws::String&& value) { m_templateNameHasBeenSet = true; m_templateName = std::move(value); }

    /**
     * <p>The name of the message template.</p>
     */
    inline void SetTemplateName(const char* value) { m_templateNameHasBeenSet = true; m_templateName.assign(value); }

    /**
     * <p>The name of the message template.</p>
     */
    inline TemplateResponse& WithTemplateName(const Aws::String& value) { SetTemplateName(value); return *this;}

    /**
     * <p>The name of the message template.</p>
     */
    inline TemplateResponse& WithTemplateName(Aws::String&& value) { SetTemplateName(std::move(value)); return *this;}

    /**
     * <p>The name of the message template.</p>
     */
    inline TemplateResponse& WithTemplateName(const char* value) { SetTemplateName(value); return *this;}


    /**
     * <p>The type of channel that the message template is designed for. Possible
     * values are: EMAIL, PUSH, SMS, and VOICE.</p>
     */
    inline const TemplateType& GetTemplateType() const{ return m_templateType; }

    /**
     * <p>The type of channel that the message template is designed for. Possible
     * values are: EMAIL, PUSH, SMS, and VOICE.</p>
     */
    inline bool TemplateTypeHasBeenSet() const { return m_templateTypeHasBeenSet; }

    /**
     * <p>The type of channel that the message template is designed for. Possible
     * values are: EMAIL, PUSH, SMS, and VOICE.</p>
     */
    inline void SetTemplateType(const TemplateType& value) { m_templateTypeHasBeenSet = true; m_templateType = value; }

    /**
     * <p>The type of channel that the message template is designed for. Possible
     * values are: EMAIL, PUSH, SMS, and VOICE.</p>
     */
    inline void SetTemplateType(TemplateType&& value) { m_templateTypeHasBeenSet = true; m_templateType = std::move(value); }

    /**
     * <p>The type of channel that the message template is designed for. Possible
     * values are: EMAIL, PUSH, SMS, and VOICE.</p>
     */
    inline TemplateResponse& WithTemplateType(const TemplateType& value) { SetTemplateType(value); return *this;}

    /**
     * <p>The type of channel that the message template is designed for. Possible
     * values are: EMAIL, PUSH, SMS, and VOICE.</p>
     */
    inline TemplateResponse& WithTemplateType(TemplateType&& value) { SetTemplateType(std::move(value)); return *this;}


    /**
     * <p>The unique identifier, as an integer, for the active version of the message
     * template.</p>
     */
    inline const Aws::String& GetVersion() const{ return m_version; }

    /**
     * <p>The unique identifier, as an integer, for the active version of the message
     * template.</p>
     */
    inline bool VersionHasBeenSet() const { return m_versionHasBeenSet; }

    /**
     * <p>The unique identifier, as an integer, for the active version of the message
     * template.</p>
     */
    inline void SetVersion(const Aws::String& value) { m_versionHasBeenSet = true; m_version = value; }

    /**
     * <p>The unique identifier, as an integer, for the active version of the message
     * template.</p>
     */
    inline void SetVersion(Aws::String&& value) { m_versionHasBeenSet = true; m_version = std::move(value); }

    /**
     * <p>The unique identifier, as an integer, for the active version of the message
     * template.</p>
     */
    inline void SetVersion(const char* value) { m_versionHasBeenSet = true; m_version.assign(value); }

    /**
     * <p>The unique identifier, as an integer, for the active version of the message
     * template.</p>
     */
    inline TemplateResponse& WithVersion(const Aws::String& value) { SetVersion(value); return *this;}

    /**
     * <p>The unique identifier, as an integer, for the active version of the message
     * template.</p>
     */
    inline TemplateResponse& WithVersion(Aws::String&& value) { SetVersion(std::move(value)); return *this;}

    /**
     * <p>The unique identifier, as an integer, for the active version of the message
     * template.</p>
     */
    inline TemplateResponse& WithVersion(const char* value) { SetVersion(value); return *this;}

  private:

    Aws::String m_arn;
    bool m_arnHasBeenSet = false;

    Aws::String m_creationDate;
    bool m_creationDateHasBeenSet = false;

    Aws::String m_defaultSubstitutions;
    bool m_defaultSubstitutionsHasBeenSet = false;

    Aws::String m_lastModifiedDate;
    bool m_lastModifiedDateHasBeenSet = false;

    Aws::Map<Aws::String, Aws::String> m_tags;
    bool m_tagsHasBeenSet = false;

    Aws::String m_templateDescription;
    bool m_templateDescriptionHasBeenSet = false;

    Aws::String m_templateName;
    bool m_templateNameHasBeenSet = false;

    TemplateType m_templateType;
    bool m_templateTypeHasBeenSet = false;

    Aws::String m_version;
    bool m_versionHasBeenSet = false;
  };

} // namespace Model
} // namespace Pinpoint
} // namespace Aws
