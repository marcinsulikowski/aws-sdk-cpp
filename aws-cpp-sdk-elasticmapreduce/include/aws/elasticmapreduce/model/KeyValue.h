﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/elasticmapreduce/EMR_EXPORTS.h>
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
namespace EMR
{
namespace Model
{

  /**
   * <p>A key-value pair.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/elasticmapreduce-2009-03-31/KeyValue">AWS
   * API Reference</a></p>
   */
  class AWS_EMR_API KeyValue
  {
  public:
    KeyValue();
    KeyValue(Aws::Utils::Json::JsonView jsonValue);
    KeyValue& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The unique identifier of a key-value pair.</p>
     */
    inline const Aws::String& GetKey() const{ return m_key; }

    /**
     * <p>The unique identifier of a key-value pair.</p>
     */
    inline bool KeyHasBeenSet() const { return m_keyHasBeenSet; }

    /**
     * <p>The unique identifier of a key-value pair.</p>
     */
    inline void SetKey(const Aws::String& value) { m_keyHasBeenSet = true; m_key = value; }

    /**
     * <p>The unique identifier of a key-value pair.</p>
     */
    inline void SetKey(Aws::String&& value) { m_keyHasBeenSet = true; m_key = std::move(value); }

    /**
     * <p>The unique identifier of a key-value pair.</p>
     */
    inline void SetKey(const char* value) { m_keyHasBeenSet = true; m_key.assign(value); }

    /**
     * <p>The unique identifier of a key-value pair.</p>
     */
    inline KeyValue& WithKey(const Aws::String& value) { SetKey(value); return *this;}

    /**
     * <p>The unique identifier of a key-value pair.</p>
     */
    inline KeyValue& WithKey(Aws::String&& value) { SetKey(std::move(value)); return *this;}

    /**
     * <p>The unique identifier of a key-value pair.</p>
     */
    inline KeyValue& WithKey(const char* value) { SetKey(value); return *this;}


    /**
     * <p>The value part of the identified key.</p>
     */
    inline const Aws::String& GetValue() const{ return m_value; }

    /**
     * <p>The value part of the identified key.</p>
     */
    inline bool ValueHasBeenSet() const { return m_valueHasBeenSet; }

    /**
     * <p>The value part of the identified key.</p>
     */
    inline void SetValue(const Aws::String& value) { m_valueHasBeenSet = true; m_value = value; }

    /**
     * <p>The value part of the identified key.</p>
     */
    inline void SetValue(Aws::String&& value) { m_valueHasBeenSet = true; m_value = std::move(value); }

    /**
     * <p>The value part of the identified key.</p>
     */
    inline void SetValue(const char* value) { m_valueHasBeenSet = true; m_value.assign(value); }

    /**
     * <p>The value part of the identified key.</p>
     */
    inline KeyValue& WithValue(const Aws::String& value) { SetValue(value); return *this;}

    /**
     * <p>The value part of the identified key.</p>
     */
    inline KeyValue& WithValue(Aws::String&& value) { SetValue(std::move(value)); return *this;}

    /**
     * <p>The value part of the identified key.</p>
     */
    inline KeyValue& WithValue(const char* value) { SetValue(value); return *this;}

  private:

    Aws::String m_key;
    bool m_keyHasBeenSet = false;

    Aws::String m_value;
    bool m_valueHasBeenSet = false;
  };

} // namespace Model
} // namespace EMR
} // namespace Aws
