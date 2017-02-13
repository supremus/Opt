#pragma once

#include <cassert>

#include "cutil.h"
#include <SimpleBuffer.h>
#include <SFSSolverInput.h>
#include "../../shared/SolverIteration.h"
#include "../../shared/CeresSolverBase.h"
class CeresImageSolver : public CeresSolverBase {

public:
    CeresImageSolver(const std::vector<unsigned int>& dims) : CeresSolverBase(dims) {}

    virtual double solve(const NamedParameters& solverParameters, const NamedParameters& problemParameters, bool profileSolve, std::vector<SolverIteration>& iters) override;

    inline int getPixel(int x, int y) const
    {
        return y * m_dims[0] + x;
    }
    std::vector<float> Xfloat;
    std::vector<float> D_i;
    std::vector<float> Im;
    std::vector<BYTE>  edgeMaskR;
    std::vector<BYTE>  edgeMaskC;
    float f_x;
    float f_y;
    float u_x;
    float u_y;
    float L[9];
};

#ifndef USE_CERES

inline void CeresImageSolver::solve(std::shared_ptr<SimpleBuffer> result, const SFSSolverInput& rawSolverInput, std::vector<SolverIteration>& solverIterations)
{

}

#endif