# Bitmask

- &
- |
- ^
- &lt;&lt;
- &gt;&gt;

## Add
```bash
n |= (1 << x)
```

## Remove
```bash
n &= ~(1 << x)
```

## Check
```bash
n&(1 << x)
```

## All
```bash
n = (1 << 21) - 1
```