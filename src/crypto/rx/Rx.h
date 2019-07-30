/* XMRig
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2017-2019 XMR-Stak    <https://github.com/fireice-uk>, <https://github.com/psychocrypt>
 * Copyright 2018      Lee Clagett <https://github.com/vtnerd>
 * Copyright 2018-2019 tevador     <tevador@gmail.com>
 * Copyright 2018-2019 SChernykh   <https://github.com/SChernykh>
 * Copyright 2016-2019 XMRig       <https://github.com/xmrig>, <support@xmrig.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef XMRIG_RX_H
#define XMRIG_RX_H


#include <stdint.h>
#include <utility>


namespace xmrig
{


class Algorithm;
class RxDataset;
class Job;


class Rx
{
public:
    static bool isReady(const Job &job, uint32_t nodeId);
    static RxDataset *dataset(uint32_t nodeId);
    static std::pair<size_t, size_t> hugePages();
    static void destroy();
    static void init();
    static void init(const Job &job, int initThreads, bool hugePages, bool numa);

private:
    static bool isReady(const uint8_t *seed, const Algorithm &algorithm, uint32_t nodeId);
    static void initDataset(uint32_t nodeId, const uint8_t *seed, const Algorithm &algorithm, uint32_t threads);
};


} /* namespace xmrig */


#endif /* XMRIG_RX_H */