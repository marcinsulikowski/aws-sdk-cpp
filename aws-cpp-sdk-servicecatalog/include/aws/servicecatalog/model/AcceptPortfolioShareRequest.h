﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/servicecatalog/ServiceCatalog_EXPORTS.h>
#include <aws/servicecatalog/ServiceCatalogRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/servicecatalog/model/PortfolioShareType.h>
#include <utility>

namespace Aws
{
namespace ServiceCatalog
{
namespace Model
{

  /**
   */
  class AWS_SERVICECATALOG_API AcceptPortfolioShareRequest : public ServiceCatalogRequest
  {
  public:
    AcceptPortfolioShareRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "AcceptPortfolioShare"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The language code.</p> <ul> <li> <p> <code>en</code> - English (default)</p>
     * </li> <li> <p> <code>jp</code> - Japanese</p> </li> <li> <p> <code>zh</code> -
     * Chinese</p> </li> </ul>
     */
    inline const Aws::String& GetAcceptLanguage() const{ return m_acceptLanguage; }

    /**
     * <p>The language code.</p> <ul> <li> <p> <code>en</code> - English (default)</p>
     * </li> <li> <p> <code>jp</code> - Japanese</p> </li> <li> <p> <code>zh</code> -
     * Chinese</p> </li> </ul>
     */
    inline bool AcceptLanguageHasBeenSet() const { return m_acceptLanguageHasBeenSet; }

    /**
     * <p>The language code.</p> <ul> <li> <p> <code>en</code> - English (default)</p>
     * </li> <li> <p> <code>jp</code> - Japanese</p> </li> <li> <p> <code>zh</code> -
     * Chinese</p> </li> </ul>
     */
    inline void SetAcceptLanguage(const Aws::String& value) { m_acceptLanguageHasBeenSet = true; m_acceptLanguage = value; }

    /**
     * <p>The language code.</p> <ul> <li> <p> <code>en</code> - English (default)</p>
     * </li> <li> <p> <code>jp</code> - Japanese</p> </li> <li> <p> <code>zh</code> -
     * Chinese</p> </li> </ul>
     */
    inline void SetAcceptLanguage(Aws::String&& value) { m_acceptLanguageHasBeenSet = true; m_acceptLanguage = std::move(value); }

    /**
     * <p>The language code.</p> <ul> <li> <p> <code>en</code> - English (default)</p>
     * </li> <li> <p> <code>jp</code> - Japanese</p> </li> <li> <p> <code>zh</code> -
     * Chinese</p> </li> </ul>
     */
    inline void SetAcceptLanguage(const char* value) { m_acceptLanguageHasBeenSet = true; m_acceptLanguage.assign(value); }

    /**
     * <p>The language code.</p> <ul> <li> <p> <code>en</code> - English (default)</p>
     * </li> <li> <p> <code>jp</code> - Japanese</p> </li> <li> <p> <code>zh</code> -
     * Chinese</p> </li> </ul>
     */
    inline AcceptPortfolioShareRequest& WithAcceptLanguage(const Aws::String& value) { SetAcceptLanguage(value); return *this;}

    /**
     * <p>The language code.</p> <ul> <li> <p> <code>en</code> - English (default)</p>
     * </li> <li> <p> <code>jp</code> - Japanese</p> </li> <li> <p> <code>zh</code> -
     * Chinese</p> </li> </ul>
     */
    inline AcceptPortfolioShareRequest& WithAcceptLanguage(Aws::String&& value) { SetAcceptLanguage(std::move(value)); return *this;}

    /**
     * <p>The language code.</p> <ul> <li> <p> <code>en</code> - English (default)</p>
     * </li> <li> <p> <code>jp</code> - Japanese</p> </li> <li> <p> <code>zh</code> -
     * Chinese</p> </li> </ul>
     */
    inline AcceptPortfolioShareRequest& WithAcceptLanguage(const char* value) { SetAcceptLanguage(value); return *this;}


    /**
     * <p>The portfolio identifier.</p>
     */
    inline const Aws::String& GetPortfolioId() const{ return m_portfolioId; }

    /**
     * <p>The portfolio identifier.</p>
     */
    inline bool PortfolioIdHasBeenSet() const { return m_portfolioIdHasBeenSet; }

    /**
     * <p>The portfolio identifier.</p>
     */
    inline void SetPortfolioId(const Aws::String& value) { m_portfolioIdHasBeenSet = true; m_portfolioId = value; }

    /**
     * <p>The portfolio identifier.</p>
     */
    inline void SetPortfolioId(Aws::String&& value) { m_portfolioIdHasBeenSet = true; m_portfolioId = std::move(value); }

    /**
     * <p>The portfolio identifier.</p>
     */
    inline void SetPortfolioId(const char* value) { m_portfolioIdHasBeenSet = true; m_portfolioId.assign(value); }

    /**
     * <p>The portfolio identifier.</p>
     */
    inline AcceptPortfolioShareRequest& WithPortfolioId(const Aws::String& value) { SetPortfolioId(value); return *this;}

    /**
     * <p>The portfolio identifier.</p>
     */
    inline AcceptPortfolioShareRequest& WithPortfolioId(Aws::String&& value) { SetPortfolioId(std::move(value)); return *this;}

    /**
     * <p>The portfolio identifier.</p>
     */
    inline AcceptPortfolioShareRequest& WithPortfolioId(const char* value) { SetPortfolioId(value); return *this;}


    /**
     * <p>The type of shared portfolios to accept. The default is to accept imported
     * portfolios.</p> <ul> <li> <p> <code>AWS_ORGANIZATIONS</code> - Accept portfolios
     * shared by the management account of your organization.</p> </li> <li> <p>
     * <code>IMPORTED</code> - Accept imported portfolios.</p> </li> <li> <p>
     * <code>AWS_SERVICECATALOG</code> - Not supported. (Throws
     * ResourceNotFoundException.)</p> </li> </ul> <p>For example, <code>aws
     * servicecatalog accept-portfolio-share --portfolio-id "port-2qwzkwxt3y5fk"
     * --portfolio-share-type AWS_ORGANIZATIONS</code> </p>
     */
    inline const PortfolioShareType& GetPortfolioShareType() const{ return m_portfolioShareType; }

    /**
     * <p>The type of shared portfolios to accept. The default is to accept imported
     * portfolios.</p> <ul> <li> <p> <code>AWS_ORGANIZATIONS</code> - Accept portfolios
     * shared by the management account of your organization.</p> </li> <li> <p>
     * <code>IMPORTED</code> - Accept imported portfolios.</p> </li> <li> <p>
     * <code>AWS_SERVICECATALOG</code> - Not supported. (Throws
     * ResourceNotFoundException.)</p> </li> </ul> <p>For example, <code>aws
     * servicecatalog accept-portfolio-share --portfolio-id "port-2qwzkwxt3y5fk"
     * --portfolio-share-type AWS_ORGANIZATIONS</code> </p>
     */
    inline bool PortfolioShareTypeHasBeenSet() const { return m_portfolioShareTypeHasBeenSet; }

    /**
     * <p>The type of shared portfolios to accept. The default is to accept imported
     * portfolios.</p> <ul> <li> <p> <code>AWS_ORGANIZATIONS</code> - Accept portfolios
     * shared by the management account of your organization.</p> </li> <li> <p>
     * <code>IMPORTED</code> - Accept imported portfolios.</p> </li> <li> <p>
     * <code>AWS_SERVICECATALOG</code> - Not supported. (Throws
     * ResourceNotFoundException.)</p> </li> </ul> <p>For example, <code>aws
     * servicecatalog accept-portfolio-share --portfolio-id "port-2qwzkwxt3y5fk"
     * --portfolio-share-type AWS_ORGANIZATIONS</code> </p>
     */
    inline void SetPortfolioShareType(const PortfolioShareType& value) { m_portfolioShareTypeHasBeenSet = true; m_portfolioShareType = value; }

    /**
     * <p>The type of shared portfolios to accept. The default is to accept imported
     * portfolios.</p> <ul> <li> <p> <code>AWS_ORGANIZATIONS</code> - Accept portfolios
     * shared by the management account of your organization.</p> </li> <li> <p>
     * <code>IMPORTED</code> - Accept imported portfolios.</p> </li> <li> <p>
     * <code>AWS_SERVICECATALOG</code> - Not supported. (Throws
     * ResourceNotFoundException.)</p> </li> </ul> <p>For example, <code>aws
     * servicecatalog accept-portfolio-share --portfolio-id "port-2qwzkwxt3y5fk"
     * --portfolio-share-type AWS_ORGANIZATIONS</code> </p>
     */
    inline void SetPortfolioShareType(PortfolioShareType&& value) { m_portfolioShareTypeHasBeenSet = true; m_portfolioShareType = std::move(value); }

    /**
     * <p>The type of shared portfolios to accept. The default is to accept imported
     * portfolios.</p> <ul> <li> <p> <code>AWS_ORGANIZATIONS</code> - Accept portfolios
     * shared by the management account of your organization.</p> </li> <li> <p>
     * <code>IMPORTED</code> - Accept imported portfolios.</p> </li> <li> <p>
     * <code>AWS_SERVICECATALOG</code> - Not supported. (Throws
     * ResourceNotFoundException.)</p> </li> </ul> <p>For example, <code>aws
     * servicecatalog accept-portfolio-share --portfolio-id "port-2qwzkwxt3y5fk"
     * --portfolio-share-type AWS_ORGANIZATIONS</code> </p>
     */
    inline AcceptPortfolioShareRequest& WithPortfolioShareType(const PortfolioShareType& value) { SetPortfolioShareType(value); return *this;}

    /**
     * <p>The type of shared portfolios to accept. The default is to accept imported
     * portfolios.</p> <ul> <li> <p> <code>AWS_ORGANIZATIONS</code> - Accept portfolios
     * shared by the management account of your organization.</p> </li> <li> <p>
     * <code>IMPORTED</code> - Accept imported portfolios.</p> </li> <li> <p>
     * <code>AWS_SERVICECATALOG</code> - Not supported. (Throws
     * ResourceNotFoundException.)</p> </li> </ul> <p>For example, <code>aws
     * servicecatalog accept-portfolio-share --portfolio-id "port-2qwzkwxt3y5fk"
     * --portfolio-share-type AWS_ORGANIZATIONS</code> </p>
     */
    inline AcceptPortfolioShareRequest& WithPortfolioShareType(PortfolioShareType&& value) { SetPortfolioShareType(std::move(value)); return *this;}

  private:

    Aws::String m_acceptLanguage;
    bool m_acceptLanguageHasBeenSet = false;

    Aws::String m_portfolioId;
    bool m_portfolioIdHasBeenSet = false;

    PortfolioShareType m_portfolioShareType;
    bool m_portfolioShareTypeHasBeenSet = false;
  };

} // namespace Model
} // namespace ServiceCatalog
} // namespace Aws
