#pragma once

#include "Drawable.h"
#include "ConstantBuffers.h"
#include <DirectXMath.h>

class TransformCbuf : public Bindable {

public:
	struct Transforms {
		DirectX::XMMATRIX modelViewProj;
		DirectX::XMMATRIX modelView;
	};
	TransformCbuf(Graphics& gfx, const Drawable& parent, UINT slot = 0u);

	void Bind(Graphics& gfx) noexcept override;
private:
	static std::unique_ptr<VertexConstantBuffer<Transforms>> pVcbuf;
	const Drawable& parent;
};