#include "math/simplex.h"

#include "math/utils.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    simplex_solver::simplex_solver()
        : size( 0 )
        , eps( 0.00001f )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    void simplex_solver::reset()
    {
        size = 0;
    }
    //////////////////////////////////////////////////////////////////////////
    void simplex_solver::addWPQ( const mt::vec3f & w, const mt::vec3f & p, const mt::vec3f & q )
    {
        W[size] = w;
        P[size] = p;
        Q[size++] = q;
    }
    //////////////////////////////////////////////////////////////////////////
    bool simplex_solver::update( mt::vec3f * const _out )
    {
        bool found = false;

        if( size == 2 )
        {
            found = solve( -W[1], W[0] - W[1], _out );
        }
        else if( size == 3 )
        {
            found = solve( -W[2], W[1] - W[2], W[0] - W[2], _out );
        }

        return found;
    }
    //////////////////////////////////////////////////////////////////////////
    void simplex_solver::remove_1()
    {
        W[0] = W[1];
        P[0] = P[1];
        Q[0] = Q[1];

        size = 1;
    }
    //////////////////////////////////////////////////////////////////////////
    void simplex_solver::remove_2()
    {
        W[1] = W[2];
        P[1] = P[2];
        Q[1] = Q[2];

        size = 2;
    }
    //////////////////////////////////////////////////////////////////////////
    bool simplex_solver::solve( const mt::vec3f & _ao, const mt::vec3f & _ab, mt::vec3f * const _out )
    {
        if( mt::dot_v3_v3( _ao, _ab ) > 0 )
        {
            mt::vec3f AC = mt::cross_v3_v3( _ab, _ao );

            float len = AC.length();

            if( len > eps )
            {
                *_out = mt::cross_v3_v3( AC, _ab );
            }
            else
            {
                return true;
            }
        }
        else
        {
            *_out = _ao;

            remove_1();
        }

        return false;
    }
    //////////////////////////////////////////////////////////////////////////
    bool simplex_solver::solve( const mt::vec3f & _ao, const mt::vec3f & _ab, const mt::vec3f & _ac, mt::vec3f * const _out )
    {
        mt::vec3f ABC = mt::cross_v3_v3( _ab, _ac );

        mt::vec3f ABCxAB = mt::cross_v3_v3( ABC, _ab );
        mt::vec3f ABCxAC = mt::cross_v3_v3( ABC, _ac );

        float AB_SIDE = mt::dot_v3_v3( ABCxAB, _ao );
        float AC_SIDE = mt::dot_v3_v3( ABCxAC, _ao );

        if( AB_SIDE < -eps )
        {
            remove_1();
            remove_2();

            bool s = solve( _ao, _ab, _out );

            return s;
        }
        else if( AC_SIDE > eps )
        {
            remove_2();

            bool s = solve( _ao, _ac, _out );

            return s;
        }

        float d = mt::dot_v3_v3( ABC, _ao );

        if( mt::equal_f_z( d ) == false )
        {
            *_out = (d > 0) ? ABC : -ABC;

            return false;
        }

        return true;
    }
    //////////////////////////////////////////////////////////////////////////
};