#ifndef SYSTEM_TEXT_ENCODING_H
#define SYSTEM_TEXT_ENCODING_H

#include "../../../Defines.h"

#include "../Object.h"
#include "../ICloneable.h"
#include "../Collections/Hashtable.h"
#include "../Int32.h"
#include "../UInt32.h"
#include "../String.h"
#include "../../../SystemTypes.h"

#include "../Globalization/EncodingTable.hpp"

namespace CppNet::System::Globalization
{
	class EncodingTable;
}

namespace CppNet::System::Collections
{
	class Hashtable;
}

namespace CppNet::System::Text
{
	using namespace CppNet::System::Collections;

	class Encoding : public Object, public ICloneable
	{
		friend class Globalization::EncodingTable;

	private:
		class CodePageDataItem
		{
		public:
			Int32 m_dataIndex = 0;
			Int32 m_uiFamilyCodePage = 0;
			String m_webName = "";
			String m_headerName = "";
			String m_bodyName = "";
			UInt32 m_flags = 0;

			CodePageDataItem(Int32 dataIndex);

			// TODO
		};

		class InternalEncodingDataItem;
		class InternalCodePageDataItem;

		class EncodingTable
		{
		private:
			static Int32 lastEncodingItem;
			static volatile Int32 lastCodePageItem;
			static Hashtable hashByName;
			static Hashtable hashByCodePage;

		public:
			static InternalEncodingDataItem* encodingDataPtr;
			static InternalCodePageDataItem *codePageDataPtr;
		};

		class InternalEncodingDataItem
		{
		public:
			SByte* webName = nullptr;
			UInt16 codePage = 0;
		};

		class InternalCodePageDataItem
		{
		public:
			UInt16 codePage = 0;
			UInt16 uiFamilyCodePage = 0;
			UInt32 flags = 0;
			SByte* Names = nullptr;
		};

	private:
		static volatile Encoding* defaultEncoding;
		static volatile Encoding* unicodeEncoding;
		static volatile Encoding* bigEndianUnicode;
		static volatile Encoding* utf7Encoding;
		static volatile Encoding* utf8Encoding;
		static volatile Encoding* utf32Encoding;
		static volatile Encoding* asciiEncoding;
		static volatile Encoding* latin1Encoding;
		static volatile Collections::Hashtable encodings;

		static const Int32 MIMECONTF_MAILNEWS;
		static const Int32 MIMECONTF_BROWSER;
		static const Int32 MIMECONTF_SAVABLE_MAILNEWS;
		static const Int32 MIMECONTF_SAVABLE_BROWSER;

		static const Int32 CodePageDefault;
		static const Int32 CodePageNoOEM;
		static const Int32 CodePageNoMac;
		static const Int32 CodePageNoThread;
		static const Int32 CodePageNoSymbol;
		static const Int32 CodePageUnicode;
		static const Int32 CodePageBigEndian;
		static const Int32 CodePageWindows1252;

		static const Int32 CodePageMacGB2312;
		static const Int32 CodePageGB2312;
		static const Int32 CodePageMacKorean;
		static const Int32 CodePageDLLKorean;

		static const Int32 ISO2022JP;
		static const Int32 ISO2022JPESC;
		static const Int32 ISO2022JPSISO;
		static const Int32 ISOKorean;
		static const Int32 ISOSimplifiedCN;
		static const Int32 EUCJP;
		static const Int32 ChineseHZ;

		static const Int32 DuplicateEUCCN;
		static const Int32 EUCCN;

		static const Int32 EUCKR;

		static const Int32 CodePageASCII;
		static const Int32 ISO_8859_1;

		static const Int32 ISCIIAssemese;
		static const Int32 ISCIIBengali;
		static const Int32 ISCIIDevanagari;
		static const Int32 ISCIIGujarathi;
		static const Int32 ISCIIKannada;
		static const Int32 ISCIIMalayalam;
		static const Int32 ISCIIOriya;
		static const Int32 ISCIIPanjabi;
		static const Int32 ISCIITamil;
		static const Int32 ISCIITelugu;

		static const Int32 GB18030;

		static const Int32 ISO_8859_8I;
		static const Int32 ISO_8859_8_Visual;

		static const Int32 ENC50229;

		static const Int32 CodePageUTF7;
		static const Int32 CodePageUTF8;
		static const Int32 CodePageUTF32;
		static const Int32 CodePageUTF32BE;

	private:
		Int32 codePage = 0;
		CodePageDataItem* dataItem = nullptr;
		Boolean deserializedFromEverett = false;
		Boolean isReadOnly = true;
	};
}

#endif