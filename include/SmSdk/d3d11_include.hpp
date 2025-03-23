#pragma once

#if defined(SMSDK_ENABLE_D3D11)
#   include <d3d11.h>
#else
typedef unsigned int DXGI_FORMAT;
struct ID3D11InputLayout;
struct ID3D11PixelShader;
struct ID3D11VertexShader;
struct ID3DBlob;
#endif