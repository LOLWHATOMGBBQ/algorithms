## Useful pragmas
  * <pre><b>#pragma</b> GCC optimize ("0fast")</pre>
    * Makes GCC auto vectorize for loops and optimizes floating points better (assumes associative and turns off denormals)
  * <pre><b>#pragma</b> GCC target ("avx, avx2")</pre> 
    * can double performance on vectorized code, but crashes old machines
  * <pre><b>#pragma</b> GCC optimize ("trapv")</pre>
    * kills programs on overflow (but is really slow)
