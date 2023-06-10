#pragma once

#include "Drawable.h"
#include "ConstantBuffers.h"
#include <DirectXMath.h>

class TransformCbuf : public Bindable {

public:
	TransformCbuf(Graphics& gfx, const Drawable& parent);

	void Bind(Graphics& gfx) noexcept override;
private:
	static std::unique_ptr<VertexConstantBuffer<DirectX::XMMATRIX>> pVcbuf;
	const Drawable& parent;
};