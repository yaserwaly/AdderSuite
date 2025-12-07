# AdderSuite Overview

**AdderSuite** is a structured C++ solution demonstrating layered design, modularity, and full development lifecycle integration.

## 🧩 Architecture Layers

- **Interfaces**:  
  Abstract contract `IAdder` defines the core addition behavior.

- **Domain Logic**:  
  `Adder` class implements overflow-safe addition with error signaling.

- **Factory Layer**:  
  `AdderFactory` provides dependency injection for Real and Stub implementations.

- **Adapter Layer**:  
  `AdderAdapter` bridges domain logic to external interfaces.

- **C-API Layer**:  
  `c_api.h` exposes a C-compatible facade using `extern "C"`.

- **Cross-Cutting Concerns**:  
  `Logger` and `Error` modules provide minimal logging and error handling.

## 🧪 Testing Strategy

- **GoogleTest + GoogleMock**:
  - `AdderReal`: Tests real logic and overflow.
  - `AdderStub`: Tests fixed return behavior.
  - `AdderMock`: Verifies call expectations.
  - `CAPI`: Validates extern "C" interface.

## 🚀 Benchmarking

- **Google Benchmark**:
  - Measures performance of `Adder::add` in Real and Stub variants.
  - Aggregates results with mean, median, stddev, and CV.

## 📊 Coverage

- **gcovr**:
  - Integrated via CMake target `coverage`.
  - Generates HTML reports for test coverage.

## 📄 Documentation

- Generated via **Doxygen** from headers and Markdown.
- Entry point: this overview.
