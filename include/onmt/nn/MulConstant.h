#pragma once

#include "onmt/nn/Module.h"

namespace onmt
{
  namespace nn
  {

    template <typename MatFwd, typename ModelT>
    class MulConstant: public Module<MatFwd>
    {
    public:
      MulConstant(th::Table* data)
        : Module<MatFwd>("nn.MulConstant")
        , _scalar(th::get_scalar<ModelT>(data, "constant_scalar"))
      {
      }

      virtual MatFwd forward_impl(MatFwd& input)
      {
        return input * _scalar;
      }

    private:
      ModelT _scalar;
    };

  }
}
