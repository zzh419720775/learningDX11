#include "Pyramid.h"
#include "BindableBase.h"

Pyramid::Pyramid(Graphics& gfx, std::mt19937& rng, std::uniform_real_distribution<float>& adist, std::uniform_real_distribution<float>& ddist, std::uniform_real_distribution<float>& odist, std::uniform_real_distribution<float>& rdist)
	:
	r(rdist(rng)),
	droll(ddist(rng)),
	dpitch(ddist(rng)),
	dphi(odist(rng)),
	dtheta(odist(rng)),
	dchi(odist(rng)),
	chi(adist(rng)),
	theta(adist(rng)),
	phi(adist(rng))
{
}

void Pyramid::Update(float dt) noexcept
{
}

DirectX::XMMATRIX Pyramid::GetTransformXM() const noexcept
{
	return DirectX::XMMATRIX();
}
