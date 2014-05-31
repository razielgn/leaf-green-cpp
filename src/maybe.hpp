#pragma once
#ifndef GL_MAYBE_HPP
#define GL_MAYBE_HPP

namespace green_leaf {
  template<class A> class Maybe {
  public:
    Maybe(const A& a)
      : a_(a)
      , valid_(true)
    {
    }

    Maybe()
      : valid_(false)
    {
    }

    bool nothing() const {
      return !valid_;
    }

    A value() const {
      return a_;
    }

  private:
    A a_;
    bool valid_;
  };

  template<class A> Maybe<A> Just(const A& a) {
    return Maybe<A>(a);
  }

  template<class A> Maybe<A> Nothing() {
    return Maybe<A>();
  }
}

#endif
