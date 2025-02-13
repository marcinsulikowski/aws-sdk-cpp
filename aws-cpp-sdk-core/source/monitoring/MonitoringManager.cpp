/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/core/utils/memory/AWSMemory.h>
#include <aws/core/monitoring/MonitoringInterface.h>
#include <aws/core/monitoring/MonitoringFactory.h>
#include <aws/core/monitoring/MonitoringManager.h>
#include <aws/core/monitoring/DefaultMonitoring.h>
#include <aws/core/Core_EXPORTS.h>

#ifdef _MSC_VER
#pragma warning(disable : 4592)
#endif

namespace Aws
{
    namespace Monitoring
    {
        typedef Aws::Vector<Aws::UniquePtr<MonitoringInterface>> Monitors;

        const char MonitoringTag[] = "MonitoringAllocTag";

        /**
         * Global factory to create global metrics instance.
         */
        static Aws::UniquePtrSafeDeleted<Monitors> s_monitors(nullptr);

        Aws::Vector<void*> OnRequestStarted(const Aws::String& serviceName, const Aws::String& requestName, const std::shared_ptr<const Aws::Http::HttpRequest>& request)
        {
            assert(s_monitors);
            Aws::Vector<void*> contexts;
            contexts.reserve(s_monitors->size());
            for (const auto& interface: *s_monitors)
            {
                contexts.emplace_back(interface->OnRequestStarted(serviceName, requestName, request));
            }
            return contexts;
        }

        void OnRequestSucceeded(const Aws::String& serviceName, const Aws::String& requestName, const std::shared_ptr<const Aws::Http::HttpRequest>& request,
                const Aws::Client::HttpResponseOutcome& outcome, const CoreMetricsCollection& metricsFromCore, const Aws::Vector<void*>& contexts)
        {
            assert(s_monitors);
            assert(contexts.size() == s_monitors->size());
            size_t index = 0;
            for (const auto& interface: *s_monitors)
            {
                interface->OnRequestSucceeded(serviceName, requestName, request, outcome, metricsFromCore, contexts[index++]);
            }
        }

        void OnRequestFailed(const Aws::String& serviceName, const Aws::String& requestName, const std::shared_ptr<const Aws::Http::HttpRequest>& request,
                const Aws::Client::HttpResponseOutcome& outcome, const CoreMetricsCollection& metricsFromCore, const Aws::Vector<void*>& contexts)
        {
            assert(s_monitors);
            assert(contexts.size() == s_monitors->size());
            size_t index = 0;
            for (const auto& interface: *s_monitors)
            {
                interface->OnRequestFailed(serviceName, requestName, request, outcome, metricsFromCore, contexts[index++]);
            }
        }

        void OnRequestRetry(const Aws::String& serviceName, const Aws::String& requestName,
                const std::shared_ptr<const Aws::Http::HttpRequest>& request, const Aws::Vector<void*>& contexts)
        {
            assert(s_monitors);
            assert(contexts.size() == s_monitors->size());
            size_t index = 0;
            for (const auto& interface: *s_monitors)
            {
                interface->OnRequestRetry(serviceName, requestName, request, contexts[index++]);
            }
        }

        void OnFinish(const Aws::String& serviceName, const Aws::String& requestName,
                const std::shared_ptr<const Aws::Http::HttpRequest>& request, const Aws::Vector<void*>& contexts)
        {
            assert(s_monitors);
            assert(contexts.size() == s_monitors->size());
            size_t index = 0;
            for (const auto& interface: *s_monitors)
            {
                interface->OnFinish(serviceName, requestName, request, contexts[index++]);
            }
        }

        void InitMonitoring(const std::vector<MonitoringFactoryCreateFunction>& monitoringFactoryCreateFunctions)
        {
            if (s_monitors)
            {
                return;
            }
            s_monitors = Aws::MakeUniqueSafeDeleted<Monitors>(MonitoringTag);
            for (const auto& function: monitoringFactoryCreateFunctions)
            {
                auto factory = function();
                if (factory)
                {
                    auto instance = factory->CreateMonitoringInstance();
                    if (instance)
                    {
                        s_monitors->emplace_back(std::move(instance));
                    }
                }
            }

            auto defaultMonitoringFactory = Aws::MakeShared<DefaultMonitoringFactory>(MonitoringTag);
            auto instance = defaultMonitoringFactory->CreateMonitoringInstance();
            if (instance)
            {
                s_monitors->emplace_back(std::move(instance));
            }
        }

        void CleanupMonitoring()
        {
            if (!s_monitors)
            {
                return;
            }

            s_monitors = nullptr;
        }
    } // namespace Monitoring

} // namespace Aws
