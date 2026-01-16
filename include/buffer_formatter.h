#pragma once
#include <format>
#include "buffer.h"

template <>
struct std::formatter<buffer, char> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    auto format(const buffer& p, std::format_context& ctx) const {
        auto out = ctx.out();

        for (int row = 0; row < p.height; ++row) {
            for (int col = 0; col < p.width; ++col) {
                *out++ = p.data[row * p.width + col];
            }

            if (row != p.height - 1) {
                *out++ = '\n';
            }
        }

        return out;
    }
};#pragma once
#include <format>
#include "buffer.h"

template <>
struct std::formatter<buffer, char> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    auto format(const buffer& p, std::format_context& ctx) const {
        auto out = ctx.out();

        for (int row = 0; row < p.height; ++row) {
            for (int col = 0; col < p.width; ++col) {
                *out++ = p.data[row * p.width + col];
            }

            if (row != p.height - 1) {
                *out++ = '\n';
            }
        }

        return out;
    }
};