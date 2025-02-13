﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/cloudfront/CloudFront_EXPORTS.h>
#include <aws/cloudfront/CloudFrontRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Http
{
    class URI;
} //namespace Http
namespace CloudFront
{
namespace Model
{

  /**
   * <p> The request to list tags for a CloudFront resource.</p><p><h3>See Also:</h3>
   * <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/cloudfront-2020-05-31/ListTagsForResourceRequest">AWS
   * API Reference</a></p>
   */
  class AWS_CLOUDFRONT_API ListTagsForResource2020_05_31Request : public CloudFrontRequest
  {
  public:
    ListTagsForResource2020_05_31Request();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "ListTagsForResource"; }

    Aws::String SerializePayload() const override;

    void AddQueryStringParameters(Aws::Http::URI& uri) const override;


    /**
     * <p> An ARN of a CloudFront resource.</p>
     */
    inline const Aws::String& GetResource() const{ return m_resource; }

    /**
     * <p> An ARN of a CloudFront resource.</p>
     */
    inline bool ResourceHasBeenSet() const { return m_resourceHasBeenSet; }

    /**
     * <p> An ARN of a CloudFront resource.</p>
     */
    inline void SetResource(const Aws::String& value) { m_resourceHasBeenSet = true; m_resource = value; }

    /**
     * <p> An ARN of a CloudFront resource.</p>
     */
    inline void SetResource(Aws::String&& value) { m_resourceHasBeenSet = true; m_resource = std::move(value); }

    /**
     * <p> An ARN of a CloudFront resource.</p>
     */
    inline void SetResource(const char* value) { m_resourceHasBeenSet = true; m_resource.assign(value); }

    /**
     * <p> An ARN of a CloudFront resource.</p>
     */
    inline ListTagsForResource2020_05_31Request& WithResource(const Aws::String& value) { SetResource(value); return *this;}

    /**
     * <p> An ARN of a CloudFront resource.</p>
     */
    inline ListTagsForResource2020_05_31Request& WithResource(Aws::String&& value) { SetResource(std::move(value)); return *this;}

    /**
     * <p> An ARN of a CloudFront resource.</p>
     */
    inline ListTagsForResource2020_05_31Request& WithResource(const char* value) { SetResource(value); return *this;}

  private:

    Aws::String m_resource;
    bool m_resourceHasBeenSet = false;
  };

} // namespace Model
} // namespace CloudFront
} // namespace Aws
