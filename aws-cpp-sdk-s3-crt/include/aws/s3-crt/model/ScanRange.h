﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3-crt/S3Crt_EXPORTS.h>

namespace Aws
{
namespace Utils
{
namespace Xml
{
  class XmlNode;
} // namespace Xml
} // namespace Utils
namespace S3Crt
{
namespace Model
{

  /**
   * <p>Specifies the byte range of the object to get the records from. A record is
   * processed when its first byte is contained by the range. This parameter is
   * optional, but when specified, it must not be empty. See RFC 2616, Section
   * 14.35.1 about how to specify the start and end of the range.</p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/s3-2006-03-01/ScanRange">AWS API
   * Reference</a></p>
   */
  class AWS_S3CRT_API ScanRange
  {
  public:
    ScanRange();
    ScanRange(const Aws::Utils::Xml::XmlNode& xmlNode);
    ScanRange& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    void AddToNode(Aws::Utils::Xml::XmlNode& parentNode) const;


    /**
     * <p>Specifies the start of the byte range. This parameter is optional. Valid
     * values: non-negative integers. The default value is 0. If only
     * <code>start</code> is supplied, it means scan from that point to the end of the
     * file. For example,
     * <code>&lt;scanrange&gt;&lt;start&gt;50&lt;/start&gt;&lt;/scanrange&gt;</code>
     * means scan from byte 50 until the end of the file.</p>
     */
    inline long long GetStart() const{ return m_start; }

    /**
     * <p>Specifies the start of the byte range. This parameter is optional. Valid
     * values: non-negative integers. The default value is 0. If only
     * <code>start</code> is supplied, it means scan from that point to the end of the
     * file. For example,
     * <code>&lt;scanrange&gt;&lt;start&gt;50&lt;/start&gt;&lt;/scanrange&gt;</code>
     * means scan from byte 50 until the end of the file.</p>
     */
    inline bool StartHasBeenSet() const { return m_startHasBeenSet; }

    /**
     * <p>Specifies the start of the byte range. This parameter is optional. Valid
     * values: non-negative integers. The default value is 0. If only
     * <code>start</code> is supplied, it means scan from that point to the end of the
     * file. For example,
     * <code>&lt;scanrange&gt;&lt;start&gt;50&lt;/start&gt;&lt;/scanrange&gt;</code>
     * means scan from byte 50 until the end of the file.</p>
     */
    inline void SetStart(long long value) { m_startHasBeenSet = true; m_start = value; }

    /**
     * <p>Specifies the start of the byte range. This parameter is optional. Valid
     * values: non-negative integers. The default value is 0. If only
     * <code>start</code> is supplied, it means scan from that point to the end of the
     * file. For example,
     * <code>&lt;scanrange&gt;&lt;start&gt;50&lt;/start&gt;&lt;/scanrange&gt;</code>
     * means scan from byte 50 until the end of the file.</p>
     */
    inline ScanRange& WithStart(long long value) { SetStart(value); return *this;}


    /**
     * <p>Specifies the end of the byte range. This parameter is optional. Valid
     * values: non-negative integers. The default value is one less than the size of
     * the object being queried. If only the End parameter is supplied, it is
     * interpreted to mean scan the last N bytes of the file. For example,
     * <code>&lt;scanrange&gt;&lt;end&gt;50&lt;/end&gt;&lt;/scanrange&gt;</code> means
     * scan the last 50 bytes.</p>
     */
    inline long long GetEnd() const{ return m_end; }

    /**
     * <p>Specifies the end of the byte range. This parameter is optional. Valid
     * values: non-negative integers. The default value is one less than the size of
     * the object being queried. If only the End parameter is supplied, it is
     * interpreted to mean scan the last N bytes of the file. For example,
     * <code>&lt;scanrange&gt;&lt;end&gt;50&lt;/end&gt;&lt;/scanrange&gt;</code> means
     * scan the last 50 bytes.</p>
     */
    inline bool EndHasBeenSet() const { return m_endHasBeenSet; }

    /**
     * <p>Specifies the end of the byte range. This parameter is optional. Valid
     * values: non-negative integers. The default value is one less than the size of
     * the object being queried. If only the End parameter is supplied, it is
     * interpreted to mean scan the last N bytes of the file. For example,
     * <code>&lt;scanrange&gt;&lt;end&gt;50&lt;/end&gt;&lt;/scanrange&gt;</code> means
     * scan the last 50 bytes.</p>
     */
    inline void SetEnd(long long value) { m_endHasBeenSet = true; m_end = value; }

    /**
     * <p>Specifies the end of the byte range. This parameter is optional. Valid
     * values: non-negative integers. The default value is one less than the size of
     * the object being queried. If only the End parameter is supplied, it is
     * interpreted to mean scan the last N bytes of the file. For example,
     * <code>&lt;scanrange&gt;&lt;end&gt;50&lt;/end&gt;&lt;/scanrange&gt;</code> means
     * scan the last 50 bytes.</p>
     */
    inline ScanRange& WithEnd(long long value) { SetEnd(value); return *this;}

  private:

    long long m_start;
    bool m_startHasBeenSet = false;

    long long m_end;
    bool m_endHasBeenSet = false;
  };

} // namespace Model
} // namespace S3Crt
} // namespace Aws
