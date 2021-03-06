/*____________________________________________________________________________

   ExifPro Image Viewer

   Copyright (C) 2000-2015 Michael Kowalski
____________________________________________________________________________*/

// BMPDecoder.cpp: implementation of the BMPDecoder class.

#include "stdafx.h"
#include "BMPDecoder.h"
#include "ColorProfile.h"
#include "BMPReader.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


BMPDecoder::BMPDecoder(const TCHAR* filePath) : filePath_(filePath), img_size_(0, 0)
{
}

BMPDecoder::~BMPDecoder()
{
}


ImageStat BMPDecoder::DecodeImg(Dib& dib, CSize& img_size, bool resize, COLORREF rgb_back/*= RGB(255,255,255)*/)
{
	BMPReader bmp;

	ImageStat stat= bmp.Open(filePath_.c_str());
	if (stat != IS_OK)
		return stat;

	img_size_ = bmp.GetSize();

	if (!bmp.IsSupported())
		return IS_FMT_NOT_SUPPORTED;

	//CSize size2= img_size;
	//if (ImageStat stat= png_.PrepareReading(CalcReductionFactor(size2, false)))
	//	return stat;

	// image may be reduced in size
	//CSize size= png_.GetResized();
	//dib.Create(size.cx, size.cy, 24);

	SetTotalLines(img_size_.cy);

	if (!LinesDecoded(0, false))
	{
//		png_.Close();
		return IS_DECODING_CANCELLED;
	}

	stat = bmp.ReadImage(dib);
	if (stat != IS_OK)
		return stat;
/*
	while (png_.GetPass() < png_.GetNoOfPasses())
	{
		while (png_.GetScanLine() < png_.GetHeight())
		{
			png_.ReadNextLine(bmp);

			if (png_.GetPass() == png_.GetNoOfPasses() - 1)
			{
				int scan_line= png_.GetScanLine();

				// report progress
				if (!LinesDecoded(scan_line, scan_line == png_.GetHeight()))
				{
					png_.Close();
					return IS_DECODING_CANCELLED;
				}
			}
		}

		png_.NextPass();
	}
*/
	if (!LinesDecoded(img_size_.cy, true))
		return IS_DECODING_CANCELLED;

	if (resize && img_size != img_size_)
		dib.ResizeToFit(img_size, Dib::RESIZE_CUBIC);

	return IS_OK;
}


CSize BMPDecoder::GetOriginalSize() const
{
	return img_size_;
}
