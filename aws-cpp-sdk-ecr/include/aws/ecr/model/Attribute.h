﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ecr/ECR_EXPORTS.h>
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
namespace ECR
{
namespace Model
{

  /**
   * <p>This data type is used in the <a>ImageScanFinding</a> data
   * type.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/ecr-2015-09-21/Attribute">AWS API
   * Reference</a></p>
   */
  class AWS_ECR_API Attribute
  {
  public:
    Attribute();
    Attribute(Aws::Utils::Json::JsonView jsonValue);
    Attribute& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The attribute key.</p>
     */
    inline const Aws::String& GetKey() const{ return m_key; }

    /**
     * <p>The attribute key.</p>
     */
    inline bool KeyHasBeenSet() const { return m_keyHasBeenSet; }

    /**
     * <p>The attribute key.</p>
     */
    inline void SetKey(const Aws::String& value) { m_keyHasBeenSet = true; m_key = value; }

    /**
     * <p>The attribute key.</p>
     */
    inline void SetKey(Aws::String&& value) { m_keyHasBeenSet = true; m_key = std::move(value); }

    /**
     * <p>The attribute key.</p>
     */
    inline void SetKey(const char* value) { m_keyHasBeenSet = true; m_key.assign(value); }

    /**
     * <p>The attribute key.</p>
     */
    inline Attribute& WithKey(const Aws::String& value) { SetKey(value); return *this;}

    /**
     * <p>The attribute key.</p>
     */
    inline Attribute& WithKey(Aws::String&& value) { SetKey(std::move(value)); return *this;}

    /**
     * <p>The attribute key.</p>
     */
    inline Attribute& WithKey(const char* value) { SetKey(value); return *this;}


    /**
     * <p>The value assigned to the attribute key.</p>
     */
    inline const Aws::String& GetValue() const{ return m_value; }

    /**
     * <p>The value assigned to the attribute key.</p>
     */
    inline bool ValueHasBeenSet() const { return m_valueHasBeenSet; }

    /**
     * <p>The value assigned to the attribute key.</p>
     */
    inline void SetValue(const Aws::String& value) { m_valueHasBeenSet = true; m_value = value; }

    /**
     * <p>The value assigned to the attribute key.</p>
     */
    inline void SetValue(Aws::String&& value) { m_valueHasBeenSet = true; m_value = std::move(value); }

    /**
     * <p>The value assigned to the attribute key.</p>
     */
    inline void SetValue(const char* value) { m_valueHasBeenSet = true; m_value.assign(value); }

    /**
     * <p>The value assigned to the attribute key.</p>
     */
    inline Attribute& WithValue(const Aws::String& value) { SetValue(value); return *this;}

    /**
     * <p>The value assigned to the attribute key.</p>
     */
    inline Attribute& WithValue(Aws::String&& value) { SetValue(std::move(value)); return *this;}

    /**
     * <p>The value assigned to the attribute key.</p>
     */
    inline Attribute& WithValue(const char* value) { SetValue(value); return *this;}

  private:

    Aws::String m_key;
    bool m_keyHasBeenSet = false;

    Aws::String m_value;
    bool m_valueHasBeenSet = false;
  };

} // namespace Model
} // namespace ECR
} // namespace Aws
