// TODO: Substitue CConvertUTF with your actual class name
unsigned long CConvertUTF::UTF32(){}
unsigned short CConvertUTF::UTF16(){}
unsigned char CConvertUTF::UTF8(){}
unsigned char CConvertUTF::Boolean(){}
enum $unnamed1$ CConvertUTF::ConversionResult(){}
enum $unnamed2$ CConvertUTF::ConversionFlags(){}
ConversionResult CConvertUTF::ConvertUTF8toUTF16(const UTF8 ** sourceStart, const UTF8 * sourceEnd, UTF16 ** targetStart, UTF16 * targetEnd, ConversionFlags flags){}
ConversionResult CConvertUTF::ConvertUTF16toUTF8(const UTF16 ** sourceStart, const UTF16 * sourceEnd, UTF8 ** targetStart, UTF8 * targetEnd, ConversionFlags flags){}
ConversionResult CConvertUTF::ConvertUTF8toUTF32(const UTF8 ** sourceStart, const UTF8 * sourceEnd, UTF32 ** targetStart, UTF32 * targetEnd, ConversionFlags flags){}
ConversionResult CConvertUTF::ConvertUTF32toUTF8(const UTF32 ** sourceStart, const UTF32 * sourceEnd, UTF8 ** targetStart, UTF8 * targetEnd, ConversionFlags flags){}
ConversionResult CConvertUTF::ConvertUTF16toUTF32(const UTF16 ** sourceStart, const UTF16 * sourceEnd, UTF32 ** targetStart, UTF32 * targetEnd, ConversionFlags flags){}
ConversionResult CConvertUTF::ConvertUTF32toUTF16(const UTF32 ** sourceStart, const UTF32 * sourceEnd, UTF16 ** targetStart, UTF16 * targetEnd, ConversionFlags flags){}
Boolean CConvertUTF::isLegalUTF8Sequence(const UTF8 * source, const UTF8 * sourceEnd){}
