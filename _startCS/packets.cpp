#include "StdAfx.h"

CPacket::CPacket()
{
    this->m_size = 0;
}

CPacket::~CPacket()
{

}

CPacket::CPacket(BYTE header,BYTE head)
{
	::memset(this->m_Packet,0,sizeof(this->m_Packet));
    if(header == 0xC1 || header == 0xC3)
	{
	this->m_Packet[0] = header;
	this->m_Packet[2] = head;
	this->m_size = 0x03;
	}
	else
	{
	this->m_Packet[0] = header;
	this->m_Packet[3] = head;
	this->m_size = 0x04;
	}
}

CPacket::CPacket(BYTE header,BYTE head,BYTE subhead)
{
	::memset(this->m_Packet,0,sizeof(this->m_Packet));
    if(header == 0xC1 || header == 0xC3)
	{
	this->m_Packet[0] = header;
	this->m_Packet[2] = head;
	this->m_Packet[3] = subhead;
	this->m_size = 0x04;
	}
	else
	{
	this->m_Packet[0] = header;
    this->m_Packet[3] = head;
	this->m_Packet[4] = subhead;
	this->m_size = 0x05;
	}
}

LPBYTE CPacket::buff()
{
    if(this->m_Packet[0] == 0xC1 || this->m_Packet[0] == 0xC3)
	{
	this->m_Packet[1] = (BYTE)this->m_size;
	}
	else
	{
    this->m_Packet[1] = HIBYTE(this->m_size);
	this->m_Packet[2] = LOBYTE(this->m_size);
	}
    return this->m_Packet;
}

DWORD CPacket::size()
{
    return this->m_size;
}

void CPacket::AddByte(BYTE Value)
{
    this->m_Packet[this->m_size] = Value;
	this->m_size++;
}

void CPacket::AddWord(WORD Value,int dir)
{
    for(int n = 1; n >= 0; n--)
	{
		int shift = (n*8);

		if(dir)
		{
			shift = 8-shift;
		}

	    this->m_Packet[this->m_size] = (BYTE)(Value >> shift);
	    this->m_size++;
	}
}
