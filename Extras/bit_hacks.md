## Useful Bit Hacks
Here are some useful bit hacks
  * `x &- x` gets the least significant bit
  * `for (int i = m; i; ) { --i &= m; ...}` This code loops over all subset masks of `m` except for `m` itself
  * `x ~= x + 1` is equivalent to `x = -x`
  * `(x << 3) + (x << 1)` is equivalent to `(x * 10)`
