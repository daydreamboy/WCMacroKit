#!/bin/sh
set -e

# Constants
BUILD_DIR="Build"
PRODUCT_DIR="Build/Product"
TARGET_NAME="WCMacroKit"
PROJECT_NAME="WCMacroKit.xcodeproj"
CONFIGURATION="Release"

ARCH_IPHONEOS="iphoneos"
ARCH_IPHONESIMULATOR="iphonesimulator"
ARCH_IPHONEUNIVERSAL="iphoneuniversal"

IPHONEOS_OUTPUT="${PRODUCT_DIR}/$CONFIGURATION-$ARCH_IPHONEOS"
IPHONEOSIMULATOR_OUTPUT="${PRODUCT_DIR}/$CONFIGURATION-$ARCH_IPHONESIMULATOR"
IPHONEUNIVERSAL_OUTPUT="${PRODUCT_DIR}/$CONFIGURATION-$ARCH_IPHONEUNIVERSAL"

rm -rf "${BUILD_DIR}"
mkdir "${BUILD_DIR}"
mkdir "${PRODUCT_DIR}"
mkdir "$IPHONEOS_OUTPUT"
mkdir "$IPHONEOSIMULATOR_OUTPUT"
mkdir "$IPHONEUNIVERSAL_OUTPUT"

xcodebuild  -project "${PROJECT_NAME}" \
            -target "${TARGET_NAME}" \
            -configuration "${CONFIGURATION}" \
            -sdk "$ARCH_IPHONEOS" \
            build \
            ONLY_ACTIVE_ARCH=NO \
            IPHONEOS_DEPLOYMENT_TARGET=8.0 \
            BUILD_DIR="${BUILD_DIR}" \
            TARGET_BUILD_DIR="${PRODUCT_DIR}/$CONFIGURATION-$ARCH_IPHONEOS"

xcodebuild  -project "${PROJECT_NAME}" \
            -target "${TARGET_NAME}" \
            -configuration "${CONFIGURATION}" \
            -sdk "$ARCH_IPHONESIMULATOR" \
            build \
            ONLY_ACTIVE_ARCH=NO \
            IPHONEOS_DEPLOYMENT_TARGET=8.0 \
            BUILD_DIR="${BUILD_DIR}" \
            TARGET_BUILD_DIR="${PRODUCT_DIR}/$CONFIGURATION-$ARCH_IPHONESIMULATOR"

cp -r "$IPHONEOS_OUTPUT/${TARGET_NAME}.framework" "$IPHONEUNIVERSAL_OUTPUT"

# if [ -f "${PRODUCT_DIR}/iphonesimulator/${TARGET_NAME}.framework/Modules/${TARGET_NAME}.swiftmodule/." ]; then
#     cp -r "${PRODUCT_DIR}/iphonesimulator/${TARGET_NAME}.framework/Modules/${TARGET_NAME}.swiftmodule/." "${PRODUCT_DIR}/${TARGET_NAME}.framework/Modules/${TARGET_NAME}.swiftmodule/"
# fi

lipo -create  "$IPHONEOS_OUTPUT/${TARGET_NAME}.framework/${TARGET_NAME}" \
			  "$IPHONEOSIMULATOR_OUTPUT/${TARGET_NAME}.framework/${TARGET_NAME}" \
	 -output "$IPHONEUNIVERSAL_OUTPUT/${TARGET_NAME}.framework/${TARGET_NAME}"

cp -r "$IPHONEUNIVERSAL_OUTPUT/${TARGET_NAME}.framework" "${PRODUCT_DIR}"
