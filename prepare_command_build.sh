#!/bin/sh
set -e

# Constants
BUILD_DIR="Build"
PRODUCT_DIR="Build/Product"
TARGET_NAME="WCMacroKit"
PROJECT_NAME="WCMacroKit.xcodeproj"
CONFIGURATION="Release"

rm -rf "${BUILD_DIR}"
mkdir "${BUILD_DIR}"
mkdir "${PRODUCT_DIR}"
mkdir "${PRODUCT_DIR}/iphoneos"
mkdir "${PRODUCT_DIR}/iphonesimulator"
mkdir "${PRODUCT_DIR}/iphoneuniversal"

xcodebuild  -project "${PROJECT_NAME}" \
            -target "${TARGET_NAME}" \
            -configuration "${CONFIGURATION}" \
            -sdk "iphoneos" \
            build \
            ONLY_ACTIVE_ARCH=NO \
            BUILD_DIR="${BUILD_DIR}" \
            TARGET_BUILD_DIR="${PRODUCT_DIR}/iphoneos"

xcodebuild  -project "${PROJECT_NAME}" \
            -target "${TARGET_NAME}" \
            -configuration "${CONFIGURATION}" \
            -sdk "iphonesimulator" \
            build \
            ONLY_ACTIVE_ARCH=NO \
            BUILD_DIR="${BUILD_DIR}" \
            TARGET_BUILD_DIR="${PRODUCT_DIR}/iphonesimulator"

# if [ -f "${PRODUCT_DIR}/iphoneos/${TARGET_NAME}.framework" ]; then
    cp -r "${PRODUCT_DIR}/iphoneos/${TARGET_NAME}.framework" "${PRODUCT_DIR}"
# fi

if [ -f "${PRODUCT_DIR}/iphonesimulator/${TARGET_NAME}.framework/Modules/${TARGET_NAME}.swiftmodule/." ]; then
    cp -r "${PRODUCT_DIR}/iphonesimulator/${TARGET_NAME}.framework/Modules/${TARGET_NAME}.swiftmodule/." "${PRODUCT_DIR}/${TARGET_NAME}.framework/Modules/${TARGET_NAME}.swiftmodule/"
fi

lipo -create  "${PRODUCT_DIR}/iphoneos/${TARGET_NAME}.framework/${TARGET_NAME}" \
			  "${PRODUCT_DIR}/iphonesimulator/${TARGET_NAME}.framework/${TARGET_NAME}" \
			  -output "${PRODUCT_DIR}/${TARGET_NAME}.framework/${TARGET_NAME}"