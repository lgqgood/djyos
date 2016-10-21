//----------------------------------------------------
// Copyright (c) 2014, SHENZHEN PENGRUI SOFT CO LTD. All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:

// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------
// Copyright (c) 2014 ����Ȩ�����������������޹�˾���С�����Ȩ�˱���һ��Ȩ����
//
// �����Ȩ�����ʹ���߷������������������£�����ʹ����ʹ�ü���ɢ����
// ������װԭʼ�뼰����λ��ִ����ʽ��Ȩ�������۴˰�װ�Ƿ񾭸�����Ȼ��
//
// 1. ���ڱ�����Դ�������ɢ�������뱣�������İ�Ȩ���桢�������б�����
//    ������������������
// 2. ���ڱ��׼�����λ��ִ����ʽ����ɢ���������������ļ��Լ�������������
//    ��ɢ����װ�е�ý�鷽ʽ����������֮��Ȩ���桢�������б����Լ�����
//    ������������

// �����������������Ǳ�������Ȩ�������Լ�����������״��"as is"���ṩ��
// ��������װ�����κ���ʾ��Ĭʾ֮�������Σ������������ھ��������Լ��ض�Ŀ
// �ĵ�������ΪĬʾ�Ե�������Ȩ�����˼�������֮�����ߣ������κ�������
// ���۳�����κ��������塢���۴�����Ϊ���Լ��ϵ���޹�ʧ������������Υ
// Լ֮��Ȩ��������ʧ������ԭ��ȣ����𣬶����κ���ʹ�ñ�������װ��������
// �κ�ֱ���ԡ�����ԡ�ż���ԡ������ԡ��ͷ��Ի��κν�����𺦣�����������
// �������Ʒ������֮���á�ʹ����ʧ��������ʧ��������ʧ��ҵ���жϵȵȣ���
// �����κ����Σ����ڸ���ʹ���ѻ���ǰ��֪���ܻ���ɴ����𺦵���������Ȼ��
//-----------------------------------------------------------------------------
// =============================================================================
// Copyright (C) 2012-2020 ��԰�̱��Զ������޹�˾ All Rights Reserved
// �ļ���     ��twi_dma.h
// ģ������: twiģ�飬XDMAD��twi�����м��
// ģ��汾: V1.00
// ������Ա: HM
// ����ʱ��: 09/11.2015
// =============================================================================

#ifndef __TWIHS_DMA_H__
#define __TWIHS_DMA_H__

#define TWIDMA_ERROR    1
#define TWIDMA_ERROR_LOCK  2

typedef void (*TwiCallback)( uint8_t, void* ) ;
typedef struct
{
	uint8_t *pBuff;				// Pointer to the Buffer.
	uint32_t BuffSize;			//Buff size in bytes.
	uint32_t ChNum;				//Dma channel num.
	TwiCallback callback;		//Callback function invoked at the end of transfer.
	void *pArgument;			//Callback arguments.
	volatile uint8_t sempaphore;//flag to indicate the current transfer.
} TwiChannel ;

typedef struct
{
	uint8_t TwiId ;
	Twihs* pTwihsHw ;
	sXdmad* pXdmad;				// Pointer to DMA driver
	TwiChannel *pRxChannel ;	//Current Rx channel
	TwiChannel *pTxChannel ;	//Current tx channel
} TwiDma;


uint32_t TWID_Configure( TwiDma *pTwid ,uint8_t TwiId);
uint32_t TWID_RcvData( TwiDma *pTwid);
uint32_t TWID_SendData( TwiDma *pTwid);
uint32_t TWID_SendPause( TwiDma *pTwid);
uint32_t TWID_RcvPause( TwiDma *pTwid);
uint32_t TWID_DisableTxChannels( TwiDma *pTwid, TwiChannel *pTxCh);
uint32_t TWID_DisableRxChannels( TwiDma *pTwid, TwiChannel *pRxCh);
uint32_t TWID_EnableTxChannels( TwiDma *pTwid, TwiChannel *pTxCh);
uint32_t TWID_EnableRxChannels( TwiDma *pTwid, TwiChannel *pTxCh);

#endif