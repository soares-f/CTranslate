#pragma once

#include "onmt/nn/Module.h"
#include "onmt/th/Obj.h"
#include "onmt/th/Utils.h"

namespace onmt
{
  namespace nn
  {

    template <typename MatFwd>
    class Replicate: public Module<MatFwd>
    {
    public:
      Replicate(th::Table* data)
        : Module<MatFwd>("nn.Replicate")
        , _dimension(th::get_number(data, "dim"))
        , _nfeatures(th::get_number(data, "nfeatures"))
      {
      }

      virtual MatFwd forward_impl(MatFwd& input) override
      {
        MatFwd output(input);

        if (_dimension == 2)
          output.setHiddenDim(_nfeatures);
        else if (_dimension == 3)
          output.setHiddenDim(input.cols());

        if (_nfeatures > 1)
          output = input.replicate(1, _nfeatures);

        return output;
      }

    private:
      int _dimension;
      int _nfeatures;
    };

  }
}
