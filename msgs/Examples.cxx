// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file Examples.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "Examples.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

VideoFrame::VideoFrame()
{
    // m_format com.eprosima.idl.parser.typecode.StringTypeCode@481a15ff
    m_format ="";
    // m_data com.eprosima.idl.parser.typecode.SequenceTypeCode@545997b1


}

VideoFrame::~VideoFrame()
{


}

VideoFrame::VideoFrame(
        const VideoFrame& x)
{
    m_format = x.m_format;
    m_data = x.m_data;
}

VideoFrame::VideoFrame(
        VideoFrame&& x)
{
    m_format = std::move(x.m_format);
    m_data = std::move(x.m_data);
}

VideoFrame& VideoFrame::operator =(
        const VideoFrame& x)
{

    m_format = x.m_format;
    m_data = x.m_data;

    return *this;
}

VideoFrame& VideoFrame::operator =(
        VideoFrame&& x)
{

    m_format = std::move(x.m_format);
    m_data = std::move(x.m_data);

    return *this;
}

bool VideoFrame::operator ==(
        const VideoFrame& x) const
{

    return (m_format == x.m_format && m_data == x.m_data);
}

bool VideoFrame::operator !=(
        const VideoFrame& x) const
{
    return !(*this == x);
}

size_t VideoFrame::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 255 + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    current_alignment += (100 * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);




    return current_alignment - initial_alignment;
}

size_t VideoFrame::getCdrSerializedSize(
        const VideoFrame& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.format().size() + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    if (data.data().size() > 0)
    {
        current_alignment += (data.data().size() * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);
    }




    return current_alignment - initial_alignment;
}

void VideoFrame::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_format;
    scdr << m_data;

}

void VideoFrame::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_format;
    dcdr >> m_data;
}

/*!
 * @brief This function copies the value in member format
 * @param _format New value to be copied in member format
 */
void VideoFrame::format(
        const std::string& _format)
{
    m_format = _format;
}

/*!
 * @brief This function moves the value in member format
 * @param _format New value to be moved in member format
 */
void VideoFrame::format(
        std::string&& _format)
{
    m_format = std::move(_format);
}

/*!
 * @brief This function returns a constant reference to member format
 * @return Constant reference to member format
 */
const std::string& VideoFrame::format() const
{
    return m_format;
}

/*!
 * @brief This function returns a reference to member format
 * @return Reference to member format
 */
std::string& VideoFrame::format()
{
    return m_format;
}
/*!
 * @brief This function copies the value in member data
 * @param _data New value to be copied in member data
 */
void VideoFrame::data(
        const std::vector<char>& _data)
{
    m_data = _data;
}

/*!
 * @brief This function moves the value in member data
 * @param _data New value to be moved in member data
 */
void VideoFrame::data(
        std::vector<char>&& _data)
{
    m_data = std::move(_data);
}

/*!
 * @brief This function returns a constant reference to member data
 * @return Constant reference to member data
 */
const std::vector<char>& VideoFrame::data() const
{
    return m_data;
}

/*!
 * @brief This function returns a reference to member data
 * @return Reference to member data
 */
std::vector<char>& VideoFrame::data()
{
    return m_data;
}

size_t VideoFrame::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;





    return current_align;
}

bool VideoFrame::isKeyDefined()
{
    return false;
}

void VideoFrame::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
      
}

VideoFrameFixed::VideoFrameFixed()
{
    // m_fmt com.eprosima.idl.parser.typecode.ArrayTypeCode@4ae82894
    memset(&m_fmt, 0, (6220800) * 1);
    // m_width com.eprosima.idl.parser.typecode.PrimitiveTypeCode@543788f3
    m_width = 0;
    // m_height com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6d3af739
    m_height = 0;
    // m_data com.eprosima.idl.parser.typecode.ArrayTypeCode@1da51a35
    memset(&m_data, 0, (6220800) * 1);

}

VideoFrameFixed::~VideoFrameFixed()
{




}

VideoFrameFixed::VideoFrameFixed(
        const VideoFrameFixed& x)
{
    m_fmt = x.m_fmt;
    m_width = x.m_width;
    m_height = x.m_height;
    m_data = x.m_data;
}

VideoFrameFixed::VideoFrameFixed(
        VideoFrameFixed&& x)
{
    m_fmt = std::move(x.m_fmt);
    m_width = x.m_width;
    m_height = x.m_height;
    m_data = std::move(x.m_data);
}

VideoFrameFixed& VideoFrameFixed::operator =(
        const VideoFrameFixed& x)
{

    m_fmt = x.m_fmt;
    m_width = x.m_width;
    m_height = x.m_height;
    m_data = x.m_data;

    return *this;
}

VideoFrameFixed& VideoFrameFixed::operator =(
        VideoFrameFixed&& x)
{

    m_fmt = std::move(x.m_fmt);
    m_width = x.m_width;
    m_height = x.m_height;
    m_data = std::move(x.m_data);

    return *this;
}

bool VideoFrameFixed::operator ==(
        const VideoFrameFixed& x) const
{

    return (m_fmt == x.m_fmt && m_width == x.m_width && m_height == x.m_height && m_data == x.m_data);
}

bool VideoFrameFixed::operator !=(
        const VideoFrameFixed& x) const
{
    return !(*this == x);
}

size_t VideoFrameFixed::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += ((6220800) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += ((6220800) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t VideoFrameFixed::getCdrSerializedSize(
        const VideoFrameFixed& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    if ((6220800) > 0)
    {
        current_alignment += ((6220800) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);
    }

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    if ((6220800) > 0)
    {
        current_alignment += ((6220800) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);
    }


    return current_alignment - initial_alignment;
}

void VideoFrameFixed::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_fmt;

    scdr << m_width;
    scdr << m_height;
    scdr << m_data;


}

void VideoFrameFixed::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_fmt;

    dcdr >> m_width;
    dcdr >> m_height;
    dcdr >> m_data;

}

/*!
 * @brief This function copies the value in member fmt
 * @param _fmt New value to be copied in member fmt
 */
void VideoFrameFixed::fmt(
        const std::array<uint8_t, 6220800>& _fmt)
{
    m_fmt = _fmt;
}

/*!
 * @brief This function moves the value in member fmt
 * @param _fmt New value to be moved in member fmt
 */
void VideoFrameFixed::fmt(
        std::array<uint8_t, 6220800>&& _fmt)
{
    m_fmt = std::move(_fmt);
}

/*!
 * @brief This function returns a constant reference to member fmt
 * @return Constant reference to member fmt
 */
const std::array<uint8_t, 6220800>& VideoFrameFixed::fmt() const
{
    return m_fmt;
}

/*!
 * @brief This function returns a reference to member fmt
 * @return Reference to member fmt
 */
std::array<uint8_t, 6220800>& VideoFrameFixed::fmt()
{
    return m_fmt;
}
/*!
 * @brief This function sets a value in member width
 * @param _width New value for member width
 */
void VideoFrameFixed::width(
        uint32_t _width)
{
    m_width = _width;
}

/*!
 * @brief This function returns the value of member width
 * @return Value of member width
 */
uint32_t VideoFrameFixed::width() const
{
    return m_width;
}

/*!
 * @brief This function returns a reference to member width
 * @return Reference to member width
 */
uint32_t& VideoFrameFixed::width()
{
    return m_width;
}

/*!
 * @brief This function sets a value in member height
 * @param _height New value for member height
 */
void VideoFrameFixed::height(
        uint32_t _height)
{
    m_height = _height;
}

/*!
 * @brief This function returns the value of member height
 * @return Value of member height
 */
uint32_t VideoFrameFixed::height() const
{
    return m_height;
}

/*!
 * @brief This function returns a reference to member height
 * @return Reference to member height
 */
uint32_t& VideoFrameFixed::height()
{
    return m_height;
}

/*!
 * @brief This function copies the value in member data
 * @param _data New value to be copied in member data
 */
void VideoFrameFixed::data(
        const std::array<uint8_t, 6220800>& _data)
{
    m_data = _data;
}

/*!
 * @brief This function moves the value in member data
 * @param _data New value to be moved in member data
 */
void VideoFrameFixed::data(
        std::array<uint8_t, 6220800>&& _data)
{
    m_data = std::move(_data);
}

/*!
 * @brief This function returns a constant reference to member data
 * @return Constant reference to member data
 */
const std::array<uint8_t, 6220800>& VideoFrameFixed::data() const
{
    return m_data;
}

/*!
 * @brief This function returns a reference to member data
 * @return Reference to member data
 */
std::array<uint8_t, 6220800>& VideoFrameFixed::data()
{
    return m_data;
}

size_t VideoFrameFixed::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;







    return current_align;
}

bool VideoFrameFixed::isKeyDefined()
{
    return false;
}

void VideoFrameFixed::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
        
}
