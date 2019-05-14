# List the source files

add_definitions(-DINITGUID)
add_definitions(-D__ANSI__)
add_definitions(-DPLATFORM_ANSI)
add_definitions(-DINITGUID)

macro(ocv_list_filterout lst regex)
    foreach(item ${${lst}})
        if(item MATCHES "${regex}")
            list(REMOVE_ITEM ${lst} "${item}")
        endif()
    endforeach()
endmacro()

set(FREEIMAGE_SRC
        FreeImage/BitmapAccess.cpp
        FreeImage/CacheFile.cpp
        FreeImage/ColorLookup.cpp
        FreeImage/Conversion.cpp
        FreeImage/Conversion16_555.cpp
        FreeImage/Conversion16_565.cpp
        FreeImage/Conversion24.cpp
        FreeImage/Conversion32.cpp
        FreeImage/ConversionRGB16.cpp
        FreeImage/Conversion4.cpp
        FreeImage/Conversion8.cpp
        FreeImage/ConversionRGBF.cpp
        FreeImage/ConversionType.cpp
        FreeImage/FreeImage.cpp
        FreeImage/FreeImageIO.cpp
        FreeImage/GetType.cpp
        FreeImage/Halftoning.cpp
        FreeImage/J2KHelper.cpp
        FreeImage/LFPQuantizer.cpp
        FreeImage/MemoryIO.cpp
        FreeImage/MNGHelper.cpp
        FreeImage/MultiPage.cpp
        FreeImage/NNQuantizer.cpp
        FreeImage/PSDParser.cpp
        FreeImage/PixelAccess.cpp
        FreeImage/Plugin.cpp
        FreeImage/PluginBMP.cpp
        FreeImage/PluginCUT.cpp
        FreeImage/PluginDDS.cpp
        FreeImage/PluginEXR.cpp
        FreeImage/PluginG3.cpp
        FreeImage/PluginGIF.cpp
        FreeImage/PluginHDR.cpp
        FreeImage/PluginICO.cpp
        FreeImage/PluginIFF.cpp
        FreeImage/PluginJ2K.cpp
        FreeImage/PluginJNG.cpp
        FreeImage/PluginJP2.cpp
        FreeImage/PluginJPEG.cpp
#        FreeImage/PluginJXR.cpp
        FreeImage/PluginKOALA.cpp
        FreeImage/PluginMNG.cpp
        FreeImage/PluginPCD.cpp
        FreeImage/PluginPCX.cpp
        FreeImage/PluginPFM.cpp
        FreeImage/PluginPICT.cpp
        FreeImage/PluginPNG.cpp
        FreeImage/PluginPNM.cpp
        FreeImage/PluginPSD.cpp
        FreeImage/PluginRAS.cpp
        FreeImage/PluginRAW.cpp
        FreeImage/PluginSGI.cpp
        FreeImage/PluginTARGA.cpp
        FreeImage/PluginTIFF.cpp
        FreeImage/PluginWBMP.cpp
        FreeImage/PluginWebP.cpp
        FreeImage/PluginXBM.cpp
        FreeImage/PluginXPM.cpp
        FreeImage/TIFFLogLuv.cpp
        FreeImage/ToneMapping.cpp
        FreeImage/WuQuantizer.cpp
        FreeImage/ZLibInterface.cpp
        FreeImage/tmoColorConvert.cpp
        FreeImage/tmoDrago03.cpp
        FreeImage/tmoFattal02.cpp
        FreeImage/tmoReinhard05.cpp
        FreeImageToolkit/BSplineRotate.cpp
        FreeImageToolkit/Background.cpp
        FreeImageToolkit/Channels.cpp
        FreeImageToolkit/ClassicRotate.cpp
        FreeImageToolkit/Colors.cpp
        FreeImageToolkit/CopyPaste.cpp
        FreeImageToolkit/Display.cpp
        FreeImageToolkit/Flip.cpp
        FreeImageToolkit/JPEGTransform.cpp
        FreeImageToolkit/MultigridPoissonSolver.cpp
        FreeImageToolkit/Rescale.cpp
        FreeImageToolkit/Resize.cpp
        )

file(GLOB LIBWEBP_SRC
        LibWebP/src/dec/*.c
        LibWebP/src/demux/*.c
        LibWebP/src/dsp/*.c
        LibWebP/src/enc/*.c
        LibWebP/src/mux/*.c
        LibWebP/src/utils/*.c
        LibWebP/src/webp/*.c)

file(GLOB OPENEXR_SRC
        OpenEXR/Half/half.cpp
        OpenEXR/Iex/*.cpp
        OpenEXR/IlmThread/*.cpp
        OpenEXR/Imath/*.cpp
        OpenEXR/IlmImf/*.cpp
        )


file(GLOB OPENEXR_HDRS
        OpenEXR/Half/*.h
        OpenEXR/Iex/Iex*.h
        OpenEXR/IlmThread/IlmThread*.h
        OpenEXR/Imath/Imath*.h
        OpenEXR/IlmImf/*.h)
ocv_list_filterout(OPENEXR_SRC IlmImf/b44ExpLogTable.cpp)
ocv_list_filterout(OPENEXR_SRC Win32.cpp)


file(GLOB LIBJXR_SRC
        LibJXR/image/decode/decode.c
        LibJXR/image/decode/JXRTranscode.c
        LibJXR/image/decode/postprocess.c
        LibJXR/image/decode/segdec.c
        LibJXR/image/decode/strdec.c
        LibJXR/image/decode/strInvTransform.c
        LibJXR/image/decode/strPredQuantDec.c
        LibJXR/image/encode/encode.c
        LibJXR/image/encode/segenc.c
        LibJXR/image/encode/strenc.c
        LibJXR/image/encode/strFwdTransform.c
        LibJXR/image/encode/strPredQuantEnc.c
        LibJXR/image/sys/adapthuff.c
        LibJXR/image/sys/image.c
        LibJXR/image/sys/perfTimerANSI.c
        LibJXR/image/sys/strcodec.c
        LibJXR/image/sys/strPredQuant.c
        LibJXR/image/sys/strTransform.c
        LibJXR/jxrgluelib/JXRGlue.c
        LibJXR/jxrgluelib/JXRGlueJxr.c
        LibJXR/jxrgluelib/JXRGluePFC.c
        LibJXR/jxrgluelib/JXRMeta.c)

set(SRCS
        Metadata/Exif.cpp
        Metadata/FIRational.cpp
        Metadata/FreeImageTag.cpp
        Metadata/IPTC.cpp
        Metadata/TagConversion.cpp
        Metadata/TagLib.cpp
        Metadata/XTIFF.cpp
        LibJPEG/jaricom.c
        LibJPEG/jcapimin.c
        LibJPEG/jcapistd.c
        LibJPEG/jcarith.c
        LibJPEG/jccoefct.c
        LibJPEG/jccolor.c
        LibJPEG/jcdctmgr.c
        LibJPEG/jchuff.c
        LibJPEG/jcinit.c
        LibJPEG/jcmainct.c
        LibJPEG/jcmarker.c
        LibJPEG/jcmaster.c
        LibJPEG/jcomapi.c
        LibJPEG/jcparam.c
        LibJPEG/jcprepct.c
        LibJPEG/jcsample.c
        LibJPEG/jctrans.c
        LibJPEG/jdapimin.c
        LibJPEG/jdapistd.c
        LibJPEG/jdarith.c
        LibJPEG/jdatadst.c
        LibJPEG/jdatasrc.c
        LibJPEG/jdcoefct.c
        LibJPEG/jdcolor.c
        LibJPEG/jddctmgr.c
        LibJPEG/jdhuff.c
        LibJPEG/jdinput.c
        LibJPEG/jdmainct.c
        LibJPEG/jdmarker.c
        LibJPEG/jdmaster.c
        LibJPEG/jdmerge.c
        LibJPEG/jdpostct.c
        LibJPEG/jdsample.c
        LibJPEG/jdtrans.c
        LibJPEG/jerror.c
        LibJPEG/jfdctflt.c
        LibJPEG/jfdctfst.c
        LibJPEG/jfdctint.c
        LibJPEG/jidctflt.c
        LibJPEG/jidctfst.c
        LibJPEG/jidctint.c
        LibJPEG/jmemmgr.c
        LibJPEG/jmemnobs.c
        LibJPEG/jquant1.c
        LibJPEG/jquant2.c
        LibJPEG/jutils.c
        LibJPEG/transupp.c
        LibOpenJPEG/bio.c
        LibOpenJPEG/cio.c
        LibOpenJPEG/dwt.c
        LibOpenJPEG/event.c
        LibOpenJPEG/function_list.c
        LibOpenJPEG/image.c
        LibOpenJPEG/invert.c
        LibOpenJPEG/j2k.c
        LibOpenJPEG/jp2.c
        LibOpenJPEG/mct.c
        LibOpenJPEG/mqc.c
        LibOpenJPEG/openjpeg.c
        LibOpenJPEG/pi.c
        LibOpenJPEG/raw.c
        LibOpenJPEG/t1.c
        LibOpenJPEG/t2.c
        LibOpenJPEG/tcd.c
        LibOpenJPEG/tgt.c
        LibPNG/png.c
        LibPNG/pngerror.c
        #LibPNG/pnggccrd.c
        LibPNG/pngget.c
        LibPNG/pngmem.c
        LibPNG/pngpread.c
        LibPNG/pngread.c
        LibPNG/pngrio.c
        LibPNG/pngrtran.c
        LibPNG/pngrutil.c
        LibPNG/pngset.c
        LibPNG/pngtrans.c
        #LibPNG/pngvcrd.c
        LibPNG/pngwio.c
        LibPNG/pngwrite.c
        LibPNG/pngwtran.c
        LibPNG/pngwutil.c
        LibRawLite/src/libraw_c_api.cpp
        LibRawLite/src/libraw_cxx.cpp
        LibRawLite/src/libraw_datastream.cpp
        LibRawLite/internal/dcraw_common.cpp
        LibRawLite/internal/dcraw_fileio.cpp
        LibRawLite/internal/demosaic_packs.cpp
        LibTIFF4/tif_aux.c
        LibTIFF4/tif_close.c
        LibTIFF4/tif_codec.c
        LibTIFF4/tif_color.c
        LibTIFF4/tif_compress.c
        LibTIFF4/tif_dir.c
        LibTIFF4/tif_dirinfo.c
        LibTIFF4/tif_dirread.c
        LibTIFF4/tif_dirwrite.c
        LibTIFF4/tif_dumpmode.c
        LibTIFF4/tif_error.c
        LibTIFF4/tif_extension.c
        LibTIFF4/tif_fax3.c
        LibTIFF4/tif_fax3sm.c
        LibTIFF4/tif_flush.c
        LibTIFF4/tif_getimage.c
        LibTIFF4/tif_jpeg.c
        LibTIFF4/tif_luv.c
        LibTIFF4/tif_lzw.c
        LibTIFF4/tif_next.c
        LibTIFF4/tif_ojpeg.c
        LibTIFF4/tif_open.c
        LibTIFF4/tif_packbits.c
        LibTIFF4/tif_pixarlog.c
        LibTIFF4/tif_predict.c
        LibTIFF4/tif_print.c
        LibTIFF4/tif_read.c
        LibTIFF4/tif_strip.c
        LibTIFF4/tif_swab.c
        LibTIFF4/tif_thunder.c
        LibTIFF4/tif_tile.c
        LibTIFF4/tif_version.c
        LibTIFF4/tif_warning.c
        LibTIFF4/tif_write.c
        LibTIFF4/tif_zip.c
        ZLib/adler32.c
        ZLib/compress.c
        ZLib/crc32.c
        ZLib/deflate.c
        ZLib/infback.c
        ZLib/inffast.c
        ZLib/inflate.c
        ZLib/inftrees.c
        ZLib/trees.c
        ZLib/uncompr.c
        ZLib/zutil.c
        )

# List the include paths
include_directories(.
        DeprecationManager
        LibRawLite
        OpenEXR
        OpenEXR/Half
        OpenEXR/Iex
        OpenEXR/IlmImf
        OpenEXR/Imath
        OpenEXR/IlmThread
        LibJXR/common/include
        LibJXR/image/sys
        LibJXR/jxrgluelib
        LibWebP
        ZLib
        )

# Declaration of the library
add_library(freeimage STATIC
        ${FREEIMAGE_SRC}
        ${LIBWEBP_SRC}
        ${OPENEXR_SRC}
        ${OPENEXR_HDRS}
        ${SRCS}
        )

# Compilation settings
set_target_properties(freeimage PROPERTIES COMPILE_DEFINITIONS "FREEIMAGE_LIB;OPJ_STATIC;LIBRAW_NODLL;LIBRAW_LIBRARY_BUILD;NO_LCMS;_CRT_SECURE_NO_DEPRECATE")

if (NOT WIN32)
    set_target_properties(freeimage PROPERTIES COMPILE_FLAGS "-w -fPIC")
else()
    set_target_properties(freeimage PROPERTIES COMPILE_FLAGS "/W0")
endif()
