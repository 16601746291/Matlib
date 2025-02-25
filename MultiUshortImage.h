#ifndef __MULTI_USHORT_IMAGE_H_
#define __MULTI_USHORT_IMAGE_H_
#include "Basicdef.h"
#include "Mat.h"
#include "MultiUcharImage.h"
#include "SingleUcharImage.h"
#include "MultiShortImage.h"
class MultiUshortImage: public CImageData_UINT16
{
public:
	int m_nRawBits;
	int m_nRawMAXS;
	int m_nRawBLC;
	int m_nRawISOGain;
	int m_nRawAwbGain[3];
	int m_nRawCCM[3][3];
	unsigned short m_nRawCFA;
	MultiUshortImage();
	bool Clone(MultiUshortImage *pInputImage);
	bool CreateImage(int width, int height, int bits);
	bool CreateImage(int width, int height, int dim, int bits);
	void CopyParameters(MultiUshortImage *pInputImage);
	bool GetBGGRMean(double fMean[]);
	int  GetRAWStride(int width, int nMIPIRAW = 0);
	bool NormalizeByOutBlcAndBit(MultiUshortImage *pInputImage, int m_nOutputBLC, int m_nOutputBits);
	void NormalizeBit(int nNewBit);
	bool ConverterRawDataToISPRawData(char *pInputRawData, int nWidth, int nHeight, int nBits, bool bHighBit, bool bByteOrder, int nMIPIRAW = 0);
	bool ConverterISPRawDataToRawData(unsigned char **pOutData, int nBits, bool bHighBit, bool bByteOrder, int &nLen, int nMIPIRAW = 0);
	bool Load16BitRawDataFromBinFile(char *pFileName, int nWidth, int nHeight, int nBits, bool bHighBit, bool bByteOrder, int nMIPIRAW=0);
	bool Load16BitRawDataFromISPRawData(unsigned short *pInputData, int nWidth, int nHeight, int nBits, bool bHighBit, bool bByteOrder, int nMIPIRAW);	
	bool Save16BitRawToBinFile(char *pFileName, int nBits, bool bHighBit, bool bByteOrder, int nMIPIRAW = 0);
	bool Save16BitRawToBitmapFile(char *pFileName, bool bBlackWhite = true);
};
#endif