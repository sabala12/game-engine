//
// Created by eran on 2/4/16.
//

#ifndef GAME_ENGINE_FEATURE_CONSTRAINT_H
#define GAME_ENGINE_FEATURE_CONSTRAINT_H

namespace Engine
{
    template <class Feature>
    class FeatureConstraint
    {
    private:
        static void constraints(Feature* feature) {
            typename Feature::ExecuteOutput execute_result = feature->Execute(typename Feature::ExecuteInput());
        }

    public:
        FeatureConstraint() {
            void(*p)(Feature*) = constraints;
        }
    };
}

#endif //GAME_ENGINE_FEATURE_CONSTRAINT_H
