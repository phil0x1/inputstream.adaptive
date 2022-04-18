/*
 *  Copyright (C) 2021 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "RepresentationChooser.h"

namespace CHOOSER
{

class ATTR_DLL_LOCAL CRepresentationChooserManualOSD : public IRepresentationChooser
{
public:
  CRepresentationChooserManualOSD();
  ~CRepresentationChooserManualOSD() override {}

  virtual void Initialize(const UTILS::PROPERTIES::KodiProperties& kodiProps) override;

  virtual void PostInit() override;

  virtual UTILS::SETTINGS::StreamSelection GetStreamSelectionMode() override
  {
    return m_streamSelectionMode;
  }

  adaptive::AdaptiveTree::Representation* ChooseRepresentation(
      adaptive::AdaptiveTree::AdaptationSet* adp) override;

  adaptive::AdaptiveTree::Representation* ChooseNextRepresentation(
      adaptive::AdaptiveTree::AdaptationSet* adp,
      adaptive::AdaptiveTree::Representation* currentRep) override;

protected:
  void RefreshResolution();

  UTILS::SETTINGS::StreamSelection m_streamSelectionMode{UTILS::SETTINGS::StreamSelection::AUTO};

  int m_screenWidth{0};
  int m_screenHeight{0};

  std::string m_screenWidthMax; // Max resolution for non-protected video content
  std::string m_screenWidthMaxSecure; // Max resolution for protected video content
};

} // namespace CHOOSER