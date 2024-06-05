//
// Copyright (C) 2023 Intel Corporation
// SPDX-License-Identifier: Apache 2.0
//

#pragma once

#include <hpi_common_interface.hpp>
#include <vpux_headers/buffer_manager.hpp>
#include <vpux_headers/device_buffer.hpp>

namespace elf {
class HostParsedInference_3720 : public HostParsedInferenceCommon {
public:
    std::vector<SymbolEntry> getSymbolTable(uint8_t index) const override;
    BufferSpecs getParsedInferenceBufferSpecs() override;
    void setHostParsedInference(DeviceBuffer& devBuffer, uint64_t mapped_entry, ResourceRequirements resReq,
                                const uint64_t* perf_metrics) override;
    elf::Version getELFLibABIVersion() const override;
    elf::Version getStaticMIVersion() const override;

private:
    static constexpr uint32_t VERSION_MAJOR = 1;
    static constexpr uint32_t VERSION_MINOR = 2;
    static constexpr uint32_t VERSION_PATCH = 0;
};

}  // namespace elf
