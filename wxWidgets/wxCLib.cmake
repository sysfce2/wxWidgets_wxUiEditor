
set (wxCLib_sources
    src/jpeg/jaricom.c
    src/jpeg/jcapimin.c
    src/jpeg/jcapistd.c
    src/jpeg/jcarith.c
    src/jpeg/jccoefct.c
    src/jpeg/jccolor.c
    src/jpeg/jcdctmgr.c
    src/jpeg/jchuff.c
    src/jpeg/jcinit.c
    src/jpeg/jcmainct.c
    src/jpeg/jcmarker.c
    src/jpeg/jcmaster.c
    src/jpeg/jcomapi.c
    src/jpeg/jcparam.c
    src/jpeg/jcprepct.c
    src/jpeg/jcsample.c
    src/jpeg/jctrans.c
    src/jpeg/jdapimin.c
    src/jpeg/jdapistd.c
    src/jpeg/jdarith.c
    src/jpeg/jdatadst.c
    src/jpeg/jdatasrc.c
    src/jpeg/jdcoefct.c
    src/jpeg/jdcolor.c
    src/jpeg/jddctmgr.c
    src/jpeg/jdhuff.c
    src/jpeg/jdinput.c
    src/jpeg/jdmainct.c
    src/jpeg/jdmarker.c
    src/jpeg/jdmaster.c
    src/jpeg/jdmerge.c
    src/jpeg/jdpostct.c
    src/jpeg/jdsample.c
    src/jpeg/jdtrans.c
    src/jpeg/jerror.c
    src/jpeg/jfdctflt.c
    src/jpeg/jfdctfst.c
    src/jpeg/jfdctint.c
    src/jpeg/jidctflt.c
    src/jpeg/jidctfst.c
    src/jpeg/jidctint.c
    src/jpeg/jmemmgr.c
    src/jpeg/jmemnobs.c
    src/jpeg/jquant1.c
    src/jpeg/jquant2.c
    src/jpeg/jutils.c

    src/tiff/libtiff/tif_aux.c
    src/tiff/libtiff/tif_close.c
    src/tiff/libtiff/tif_codec.c
    src/tiff/libtiff/tif_color.c
    src/tiff/libtiff/tif_compress.c
    src/tiff/libtiff/tif_dir.c
    src/tiff/libtiff/tif_dirinfo.c
    src/tiff/libtiff/tif_dirread.c
    src/tiff/libtiff/tif_dirwrite.c
    src/tiff/libtiff/tif_dumpmode.c
    src/tiff/libtiff/tif_error.c
    src/tiff/libtiff/tif_extension.c
    src/tiff/libtiff/tif_fax3.c
    src/tiff/libtiff/tif_fax3sm.c
    src/tiff/libtiff/tif_flush.c
    src/tiff/libtiff/tif_getimage.c
    src/tiff/libtiff/tif_jbig.c
    src/tiff/libtiff/tif_jpeg.c
    src/tiff/libtiff/tif_jpeg_12.c
    src/tiff/libtiff/tif_luv.c
    src/tiff/libtiff/tif_lzma.c
    src/tiff/libtiff/tif_lzw.c
    src/tiff/libtiff/tif_next.c
    src/tiff/libtiff/tif_ojpeg.c
    src/tiff/libtiff/tif_open.c
    src/tiff/libtiff/tif_packbits.c
    src/tiff/libtiff/tif_pixarlog.c
    src/tiff/libtiff/tif_predict.c
    src/tiff/libtiff/tif_print.c
    src/tiff/libtiff/tif_read.c
    src/tiff/libtiff/tif_strip.c
    src/tiff/libtiff/tif_swab.c
    src/tiff/libtiff/tif_thunder.c
    src/tiff/libtiff/tif_tile.c
    src/tiff/libtiff/tif_version.c
    src/tiff/libtiff/tif_warning.c
    src/tiff/libtiff/tif_webp.c
    # src/tiff/libtiff/tif_win32.c
    src/tiff/libtiff/tif_write.c
    src/tiff/libtiff/tif_zip.c
    src/tiff/libtiff/tif_zstd.c

    src/png/png.c
    src/png/pngerror.c
    src/png/pngget.c
    src/png/pngmem.c
    src/png/pngpread.c
    src/png/pngread.c
    src/png/pngrio.c
    src/png/pngrtran.c
    src/png/pngrutil.c
    src/png/pngset.c
    src/png/pngtrans.c
    src/png/pngwio.c
    src/png/pngwrite.c
    src/png/pngwtran.c
    src/png/pngwutil.c
    src/png/arm/arm_init.c
    src/png/arm/filter_neon_intrinsics.c
    src/png/arm/palette_neon_intrinsics.c
    src/png/intel/intel_init.c
    src/png/intel/filter_sse2_intrinsics.c

    src/zlib/adler32.c
    src/zlib/compress.c
    src/zlib/crc32.c
    src/zlib/deflate.c
    src/zlib/gzclose.c
    src/zlib/gzlib.c
    src/zlib/gzread.c
    src/zlib/gzwrite.c
    src/zlib/infback.c
    src/zlib/inffast.c
    src/zlib/inflate.c
    src/zlib/inftrees.c
    src/zlib/trees.c
    src/zlib/uncompr.c
    src/zlib/zutil.c

    3rdparty/pcre/src/pcre2_auto_possess.c
    3rdparty/pcre/src/pcre2_chartables.c
    3rdparty/pcre/src/pcre2_compile.c
    3rdparty/pcre/src/pcre2_config.c
    3rdparty/pcre/src/pcre2_context.c
    3rdparty/pcre/src/pcre2_convert.c
    3rdparty/pcre/src/pcre2_dfa_match.c
    3rdparty/pcre/src/pcre2_error.c
    3rdparty/pcre/src/pcre2_extuni.c
    3rdparty/pcre/src/pcre2_find_bracket.c
    3rdparty/pcre/src/pcre2_jit_compile.c
    3rdparty/pcre/src/pcre2_maketables.c
    3rdparty/pcre/src/pcre2_match.c
    3rdparty/pcre/src/pcre2_match_data.c
    3rdparty/pcre/src/pcre2_newline.c
    3rdparty/pcre/src/pcre2_ord2utf.c
    3rdparty/pcre/src/pcre2_pattern_info.c
    3rdparty/pcre/src/pcre2_script_run.c
    3rdparty/pcre/src/pcre2_serialize.c
    3rdparty/pcre/src/pcre2_string_utils.c
    3rdparty/pcre/src/pcre2_study.c
    3rdparty/pcre/src/pcre2_substitute.c
    3rdparty/pcre/src/pcre2_substring.c
    3rdparty/pcre/src/pcre2_tables.c
    3rdparty/pcre/src/pcre2_ucd.c
    3rdparty/pcre/src/pcre2_valid_utf.c
    3rdparty/pcre/src/pcre2_xclass.c

    # wx_wxexpat
    src/expat/expat/lib/xmlparse.c
    src/expat/expat/lib/xmlrole.c
    src/expat/expat/lib/xmltok.c

    # plutovg used by lunasvg
    # Note that there is a non-official version of these as C++ code
    # 3rdparty/lunasvg/3rdparty/plutovg/plutovg-blend.c
    # 3rdparty/lunasvg/3rdparty/plutovg/plutovg-dash.c
    # 3rdparty/lunasvg/3rdparty/plutovg/plutovg-ft-math.c
    # 3rdparty/lunasvg/3rdparty/plutovg/plutovg-ft-raster.c
    # 3rdparty/lunasvg/3rdparty/plutovg/plutovg-ft-stroker.c
    # 3rdparty/lunasvg/3rdparty/plutovg/plutovg-geometry.c
    # 3rdparty/lunasvg/3rdparty/plutovg/plutovg-paint.c
    # 3rdparty/lunasvg/3rdparty/plutovg/plutovg-rle.c
    # 3rdparty/lunasvg/3rdparty/plutovg/plutovg.c

    # wxBase
    src/common/extended.c
)
