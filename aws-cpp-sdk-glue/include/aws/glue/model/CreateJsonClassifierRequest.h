﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/glue/Glue_EXPORTS.h>
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
namespace Glue
{
namespace Model
{

  /**
   * <p>Specifies a JSON classifier for <code>CreateClassifier</code> to
   * create.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/glue-2017-03-31/CreateJsonClassifierRequest">AWS
   * API Reference</a></p>
   */
  class AWS_GLUE_API CreateJsonClassifierRequest
  {
  public:
    CreateJsonClassifierRequest();
    CreateJsonClassifierRequest(Aws::Utils::Json::JsonView jsonValue);
    CreateJsonClassifierRequest& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The name of the classifier.</p>
     */
    inline const Aws::String& GetName() const{ return m_name; }

    /**
     * <p>The name of the classifier.</p>
     */
    inline bool NameHasBeenSet() const { return m_nameHasBeenSet; }

    /**
     * <p>The name of the classifier.</p>
     */
    inline void SetName(const Aws::String& value) { m_nameHasBeenSet = true; m_name = value; }

    /**
     * <p>The name of the classifier.</p>
     */
    inline void SetName(Aws::String&& value) { m_nameHasBeenSet = true; m_name = std::move(value); }

    /**
     * <p>The name of the classifier.</p>
     */
    inline void SetName(const char* value) { m_nameHasBeenSet = true; m_name.assign(value); }

    /**
     * <p>The name of the classifier.</p>
     */
    inline CreateJsonClassifierRequest& WithName(const Aws::String& value) { SetName(value); return *this;}

    /**
     * <p>The name of the classifier.</p>
     */
    inline CreateJsonClassifierRequest& WithName(Aws::String&& value) { SetName(std::move(value)); return *this;}

    /**
     * <p>The name of the classifier.</p>
     */
    inline CreateJsonClassifierRequest& WithName(const char* value) { SetName(value); return *this;}


    /**
     * <p>A <code>JsonPath</code> string defining the JSON data for the classifier to
     * classify. Glue supports a subset of JsonPath, as described in <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/custom-classifier.html#custom-classifier-json">Writing
     * JsonPath Custom Classifiers</a>.</p>
     */
    inline const Aws::String& GetJsonPath() const{ return m_jsonPath; }

    /**
     * <p>A <code>JsonPath</code> string defining the JSON data for the classifier to
     * classify. Glue supports a subset of JsonPath, as described in <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/custom-classifier.html#custom-classifier-json">Writing
     * JsonPath Custom Classifiers</a>.</p>
     */
    inline bool JsonPathHasBeenSet() const { return m_jsonPathHasBeenSet; }

    /**
     * <p>A <code>JsonPath</code> string defining the JSON data for the classifier to
     * classify. Glue supports a subset of JsonPath, as described in <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/custom-classifier.html#custom-classifier-json">Writing
     * JsonPath Custom Classifiers</a>.</p>
     */
    inline void SetJsonPath(const Aws::String& value) { m_jsonPathHasBeenSet = true; m_jsonPath = value; }

    /**
     * <p>A <code>JsonPath</code> string defining the JSON data for the classifier to
     * classify. Glue supports a subset of JsonPath, as described in <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/custom-classifier.html#custom-classifier-json">Writing
     * JsonPath Custom Classifiers</a>.</p>
     */
    inline void SetJsonPath(Aws::String&& value) { m_jsonPathHasBeenSet = true; m_jsonPath = std::move(value); }

    /**
     * <p>A <code>JsonPath</code> string defining the JSON data for the classifier to
     * classify. Glue supports a subset of JsonPath, as described in <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/custom-classifier.html#custom-classifier-json">Writing
     * JsonPath Custom Classifiers</a>.</p>
     */
    inline void SetJsonPath(const char* value) { m_jsonPathHasBeenSet = true; m_jsonPath.assign(value); }

    /**
     * <p>A <code>JsonPath</code> string defining the JSON data for the classifier to
     * classify. Glue supports a subset of JsonPath, as described in <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/custom-classifier.html#custom-classifier-json">Writing
     * JsonPath Custom Classifiers</a>.</p>
     */
    inline CreateJsonClassifierRequest& WithJsonPath(const Aws::String& value) { SetJsonPath(value); return *this;}

    /**
     * <p>A <code>JsonPath</code> string defining the JSON data for the classifier to
     * classify. Glue supports a subset of JsonPath, as described in <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/custom-classifier.html#custom-classifier-json">Writing
     * JsonPath Custom Classifiers</a>.</p>
     */
    inline CreateJsonClassifierRequest& WithJsonPath(Aws::String&& value) { SetJsonPath(std::move(value)); return *this;}

    /**
     * <p>A <code>JsonPath</code> string defining the JSON data for the classifier to
     * classify. Glue supports a subset of JsonPath, as described in <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/custom-classifier.html#custom-classifier-json">Writing
     * JsonPath Custom Classifiers</a>.</p>
     */
    inline CreateJsonClassifierRequest& WithJsonPath(const char* value) { SetJsonPath(value); return *this;}

  private:

    Aws::String m_name;
    bool m_nameHasBeenSet = false;

    Aws::String m_jsonPath;
    bool m_jsonPathHasBeenSet = false;
  };

} // namespace Model
} // namespace Glue
} // namespace Aws
