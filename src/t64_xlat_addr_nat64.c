/*
Copyright (c) 2022 Vít Labuda. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
following conditions are met:
 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following
    disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
    following disclaimer in the documentation and/or other materials provided with the distribution.
 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote
    products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include"t64_tundra.h"
#include"t64_xlat_addr_nat64.h"

#include"t64_utils_xlat_addr.h"


bool t64f_xlat_addr_nat64__perform_4to6_address_translation_for_main_packet(t64ts_tundra__xlat_thread_context *context, const uint8_t *in_src_ipv4, const uint8_t *in_dst_ipv4, uint8_t *out_src_ipv6, uint8_t *out_dst_ipv6) {
    if(!t64f_utils_xlat_addr__nat64_clat__perform_4to6_prefix_translation_for_main_packet(context, in_src_ipv4, out_src_ipv6))
        return false;

    return t64f_utils_xlat_addr__nat64_clat__perform_4to6_translator_ip_translation(context, in_dst_ipv4, out_dst_ipv6);
}

bool t64f_xlat_addr_nat64__perform_4to6_address_translation_for_icmp_error_packet(t64ts_tundra__xlat_thread_context *context, const uint8_t *in_src_ipv4, const uint8_t *in_dst_ipv4, uint8_t *out_src_ipv6, uint8_t *out_dst_ipv6) {
    t64f_utils_xlat_addr__nat64_clat_siit__perform_4to6_prefix_translation_for_icmp_error_packet(context, in_dst_ipv4, out_dst_ipv6);

    return t64f_utils_xlat_addr__nat64_clat__perform_4to6_translator_ip_translation(context, in_src_ipv4, out_src_ipv6);
}

bool t64f_xlat_addr_nat64__perform_6to4_address_translation_for_main_packet(t64ts_tundra__xlat_thread_context *context, const uint8_t *in_src_ipv6, const uint8_t *in_dst_ipv6, uint8_t *out_src_ipv4, uint8_t *out_dst_ipv4) {
    if(!t64f_utils_xlat_addr__nat64_clat__perform_6to4_translator_ip_translation(context, in_src_ipv6, out_src_ipv4))
        return false;

    return t64f_utils_xlat_addr__nat64_clat__perform_6to4_prefix_translation_for_main_packet(context, in_dst_ipv6, out_dst_ipv4);
}

bool t64f_xlat_addr_nat64__perform_6to4_address_translation_for_icmp_error_packet(t64ts_tundra__xlat_thread_context *context, const uint8_t *in_src_ipv6, const uint8_t *in_dst_ipv6, uint8_t *out_src_ipv4, uint8_t *out_dst_ipv4) {
    if(!t64f_utils_xlat_addr__nat64_clat_siit__perform_6to4_prefix_translation_for_icmp_error_packet(context, in_src_ipv6, out_src_ipv4))
        return false;

    return t64f_utils_xlat_addr__nat64_clat__perform_6to4_translator_ip_translation(context, in_dst_ipv6, out_dst_ipv4);
}
