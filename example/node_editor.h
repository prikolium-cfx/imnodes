#pragma once

#include <cmath>

#include <imgui.h>
#include <imnodes.h>

namespace example
{
inline void HandleEditorZoom()
{
    ImGuiIO& io = ImGui::GetIO();
    if (!ImNodes::IsEditorHovered())
        return;

    const float wheel = io.MouseWheel;
    if (wheel == 0.0f)
        return;

    constexpr float zoom_base = 1.1f;
    const float zoom_multiplier = static_cast<float>(std::pow(zoom_base, wheel));
    const float new_zoom = ImNodes::EditorContextGetZoom() * zoom_multiplier;

    ImNodes::EditorContextSetZoom(new_zoom, ImGui::GetMousePos());
}

void NodeEditorInitialize();
void NodeEditorShow();
void NodeEditorShutdown();
} // namespace example