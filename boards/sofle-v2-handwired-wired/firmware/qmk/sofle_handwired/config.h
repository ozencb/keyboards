#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

// macOS can hold a new accessory for seconds before configuring it; the default 2 s makes the USB half give up and disconnect
#define SPLIT_USB_TIMEOUT 5000
