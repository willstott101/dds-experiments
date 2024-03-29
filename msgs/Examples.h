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
 * @file Examples.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_EXAMPLES_H_
#define _FAST_DDS_GENERATED_EXAMPLES_H_


#include <stdint.h>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <bitset>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define eProsima_user_DllExport
#endif  // _WIN32

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(Examples_SOURCE)
#define Examples_DllAPI __declspec( dllexport )
#else
#define Examples_DllAPI __declspec( dllimport )
#endif // Examples_SOURCE
#else
#define Examples_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define Examples_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima


/*!
 * @brief This class represents the structure VideoFrame defined by the user in the IDL file.
 * @ingroup EXAMPLES
 */
class VideoFrame
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport VideoFrame();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~VideoFrame();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object VideoFrame that will be copied.
     */
    eProsima_user_DllExport VideoFrame(
            const VideoFrame& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object VideoFrame that will be copied.
     */
    eProsima_user_DllExport VideoFrame(
            VideoFrame&& x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object VideoFrame that will be copied.
     */
    eProsima_user_DllExport VideoFrame& operator =(
            const VideoFrame& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object VideoFrame that will be copied.
     */
    eProsima_user_DllExport VideoFrame& operator =(
            VideoFrame&& x);

    /*!
     * @brief Comparison operator.
     * @param x VideoFrame object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const VideoFrame& x) const;

    /*!
     * @brief Comparison operator.
     * @param x VideoFrame object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const VideoFrame& x) const;

    /*!
     * @brief This function copies the value in member format
     * @param _format New value to be copied in member format
     */
    eProsima_user_DllExport void format(
            const std::string& _format);

    /*!
     * @brief This function moves the value in member format
     * @param _format New value to be moved in member format
     */
    eProsima_user_DllExport void format(
            std::string&& _format);

    /*!
     * @brief This function returns a constant reference to member format
     * @return Constant reference to member format
     */
    eProsima_user_DllExport const std::string& format() const;

    /*!
     * @brief This function returns a reference to member format
     * @return Reference to member format
     */
    eProsima_user_DllExport std::string& format();
    /*!
     * @brief This function copies the value in member data
     * @param _data New value to be copied in member data
     */
    eProsima_user_DllExport void data(
            const std::vector<char>& _data);

    /*!
     * @brief This function moves the value in member data
     * @param _data New value to be moved in member data
     */
    eProsima_user_DllExport void data(
            std::vector<char>&& _data);

    /*!
     * @brief This function returns a constant reference to member data
     * @return Constant reference to member data
     */
    eProsima_user_DllExport const std::vector<char>& data() const;

    /*!
     * @brief This function returns a reference to member data
     * @return Reference to member data
     */
    eProsima_user_DllExport std::vector<char>& data();

    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const VideoFrame& data,
            size_t current_alignment = 0);


    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(
            eprosima::fastcdr::Cdr& cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(
            eprosima::fastcdr::Cdr& cdr);



    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(
            eprosima::fastcdr::Cdr& cdr) const;

private:

    std::string m_format;
    std::vector<char> m_data;
};
/*!
 * @brief This class represents the structure VideoFrameFixed defined by the user in the IDL file.
 * @ingroup EXAMPLES
 */
class VideoFrameFixed
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport VideoFrameFixed();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~VideoFrameFixed();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object VideoFrameFixed that will be copied.
     */
    eProsima_user_DllExport VideoFrameFixed(
            const VideoFrameFixed& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object VideoFrameFixed that will be copied.
     */
    eProsima_user_DllExport VideoFrameFixed(
            VideoFrameFixed&& x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object VideoFrameFixed that will be copied.
     */
    eProsima_user_DllExport VideoFrameFixed& operator =(
            const VideoFrameFixed& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object VideoFrameFixed that will be copied.
     */
    eProsima_user_DllExport VideoFrameFixed& operator =(
            VideoFrameFixed&& x);

    /*!
     * @brief Comparison operator.
     * @param x VideoFrameFixed object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const VideoFrameFixed& x) const;

    /*!
     * @brief Comparison operator.
     * @param x VideoFrameFixed object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const VideoFrameFixed& x) const;

    /*!
     * @brief This function copies the value in member format
     * @param _format New value to be copied in member format
     */
    eProsima_user_DllExport void format(
            const std::array<uint8_t, 32>& _format);

    /*!
     * @brief This function moves the value in member format
     * @param _format New value to be moved in member format
     */
    eProsima_user_DllExport void format(
            std::array<uint8_t, 32>&& _format);

    /*!
     * @brief This function returns a constant reference to member format
     * @return Constant reference to member format
     */
    eProsima_user_DllExport const std::array<uint8_t, 32>& format() const;

    /*!
     * @brief This function returns a reference to member format
     * @return Reference to member format
     */
    eProsima_user_DllExport std::array<uint8_t, 32>& format();
    /*!
     * @brief This function sets a value in member width
     * @param _width New value for member width
     */
    eProsima_user_DllExport void width(
            uint32_t _width);

    /*!
     * @brief This function returns the value of member width
     * @return Value of member width
     */
    eProsima_user_DllExport uint32_t width() const;

    /*!
     * @brief This function returns a reference to member width
     * @return Reference to member width
     */
    eProsima_user_DllExport uint32_t& width();

    /*!
     * @brief This function sets a value in member height
     * @param _height New value for member height
     */
    eProsima_user_DllExport void height(
            uint32_t _height);

    /*!
     * @brief This function returns the value of member height
     * @return Value of member height
     */
    eProsima_user_DllExport uint32_t height() const;

    /*!
     * @brief This function returns a reference to member height
     * @return Reference to member height
     */
    eProsima_user_DllExport uint32_t& height();

    /*!
     * @brief This function copies the value in member data
     * @param _data New value to be copied in member data
     */
    eProsima_user_DllExport void data(
            const std::array<uint8_t, 6220800>& _data);

    /*!
     * @brief This function moves the value in member data
     * @param _data New value to be moved in member data
     */
    eProsima_user_DllExport void data(
            std::array<uint8_t, 6220800>&& _data);

    /*!
     * @brief This function returns a constant reference to member data
     * @return Constant reference to member data
     */
    eProsima_user_DllExport const std::array<uint8_t, 6220800>& data() const;

    /*!
     * @brief This function returns a reference to member data
     * @return Reference to member data
     */
    eProsima_user_DllExport std::array<uint8_t, 6220800>& data();

    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const VideoFrameFixed& data,
            size_t current_alignment = 0);


    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(
            eprosima::fastcdr::Cdr& cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(
            eprosima::fastcdr::Cdr& cdr);



    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(
            eprosima::fastcdr::Cdr& cdr) const;

private:

    std::array<uint8_t, 32> m_format;
    uint32_t m_width;
    uint32_t m_height;
    std::array<uint8_t, 6220800> m_data;
};

#endif // _FAST_DDS_GENERATED_EXAMPLES_H_