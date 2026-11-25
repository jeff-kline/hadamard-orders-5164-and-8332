length == 1 and (.[0] |
  ([.order, .reflection_cells, .g, .form, .q, .W] == $expected)
  and (.order == .expected_order and .q_mod_4 == 1)
  and ([.entries_pm1, .gram_exact, .q_prime, .golay_ok,
        .aperiodic_norm_sum_constant, .weighing_ok, .cells_are_H2,
        .core_ok] | all(. == true)))
