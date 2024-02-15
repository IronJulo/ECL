# ECL - Embedded Core Library

## Overview
ECL (Embedded Core Library) is more like a cluster of library (for most header only) that help developping in an embedded environnement. Designed to provide core functionalities for embedded software development. It emphasizes portability and ease of use by abstracting hardware interfaces, allowing developers to focus on application logic rather than hardware specifics. The library includes abstract classes for common hardware interfaces such as SPI, i2c allowing users to implement their own hardware-specific drivers and bind them to already existing libraries with minimal effort.

## Key Features

- **Hardware Abstraction**: Abstract classes for hardware interfaces like SPI, I2C, UART, etc., enabling easy integration with different hardware platforms.
- **User-defined Implementations**: Users can create their own implementations of abstract classes to interface with their hardware's HAL (Hardware Abstraction Layer) seamlessly.
- **Modularity**: Designed with modularity in mind, allowing developers to include only the components they need, optimizing resource usage for embedded environments.
- **Zero-platform Support**: Crafted with no specific hardware in mind. The best way to be compatible with every hardware is to be compatible with none.

## README in Construction
**Please note**: This README is currently under construction and subject to change as the library evolves. Stay tuned for updates and enhancements.
