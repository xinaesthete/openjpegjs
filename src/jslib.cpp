// Copyright (c) Chris Hafey.
// SPDX-License-Identifier: MIT


#include "J2KDecoder.hpp"
//#include "HTJ2KEncoder.hpp"
#include "FrameInfo.hpp"
#include "Point.hpp"
#include "Size.hpp"

#include <emscripten.h>
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(FrameInfo) {
  value_object<FrameInfo>("FrameInfo")
    .field("width", &FrameInfo::width)
    .field("height", &FrameInfo::height)
    .field("bitsPerSample", &FrameInfo::bitsPerSample)
    .field("componentCount", &FrameInfo::componentCount)
    .field("isSigned", &FrameInfo::isSigned)
       ;
}

EMSCRIPTEN_BINDINGS(Point) {
  value_object<Point>("Point")
    .field("x", &Point::x)
    .field("y", &Point::y)
       ;
}

EMSCRIPTEN_BINDINGS(Size) {
  value_object<Size>("Size")
    .field("width", &Size::width)
    .field("height", &Size::height)
       ;
}

EMSCRIPTEN_BINDINGS(J2KDecoder) {
  class_<J2KDecoder>("J2KDecoder")
    .constructor<>()
    .function("getEncodedBuffer", &J2KDecoder::getEncodedBuffer)
    .function("getDecodedBuffer", &J2KDecoder::getDecodedBuffer)
    .function("readHeader", &J2KDecoder::readHeader)
    .function("calculateSizeAtDecompositionLevel", &J2KDecoder::calculateSizeAtDecompositionLevel)
    .function("decode", &J2KDecoder::decode)
    .function("decodeSubResolution", &J2KDecoder::decodeSubResolution)
    .function("getFrameInfo", &J2KDecoder::getFrameInfo)
    .function("getDownSample", &J2KDecoder::getDownSample)
    .function("getNumDecompositions", &J2KDecoder::getNumDecompositions)
    .function("getIsReversible", &J2KDecoder::getIsReversible)
    .function("getProgressionOrder", &J2KDecoder::getProgressionOrder)
    .function("getImageOffset", &J2KDecoder::getImageOffset)
    .function("getTileSize", &J2KDecoder::getTileSize)
    .function("getTileOffset", &J2KDecoder::getTileOffset)
    .function("getBlockDimensions", &J2KDecoder::getBlockDimensions)
    .function("getPrecinct", &J2KDecoder::getPrecinct)
    .function("getNumLayers", &J2KDecoder::getNumLayers)
    .function("getIsUsingColorTransform", &J2KDecoder::getIsUsingColorTransform)
   ;
}
/*

EMSCRIPTEN_BINDINGS(HTJ2KEncoder) {
  class_<HTJ2KEncoder>("HTJ2KEncoder")
    .constructor<>()
    .function("getDecodedBuffer", &HTJ2KEncoder::getDecodedBuffer)
    .function("getEncodedBuffer", &HTJ2KEncoder::getEncodedBuffer)
    .function("encode", &HTJ2KEncoder::encode)
    .function("setDecompositions", &HTJ2KEncoder::setDecompositions)
    .function("setQuality", &HTJ2KEncoder::setQuality)
    .function("setProgressionOrder", &HTJ2KEncoder::setProgressionOrder)
    .function("setDownSample", &HTJ2KEncoder::setDownSample)
    .function("setImageOffset", &HTJ2KEncoder::setImageOffset)
    .function("setTileSize", &HTJ2KEncoder::setTileSize)
    .function("setTileOffset", &HTJ2KEncoder::setTileOffset)
    .function("setBlockDimensions", &HTJ2KEncoder::setBlockDimensions)
    .function("setNumPrecincts", &HTJ2KEncoder::setNumPrecincts)
    .function("setPrecinct", &HTJ2KEncoder::setPrecinct)
    .function("setIsUsingColorTransform", &HTJ2KEncoder::setIsUsingColorTransform)
   ;
}
*/